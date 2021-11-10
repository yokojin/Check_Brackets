// String_Brackets.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <stack>
#include <cstdio>


using namespace std;
//Структура в которой конструктор с параметрами (позиция и символ в этой позиции)
struct Info {
    int Ch;
    int pos;
    Info(void) {}
    Info(int x, int po) : Ch(x), pos(po) {}
};

//Сравнение Скобок (если равны или если нет)
bool beg_ENd(int a, int  b) {

    return (a == '(' && b == ')') ||
        (a == '{' && b == '}') ||
        (a == '[' && b == ']');

}
bool CheckChar_A(const char* ar_R, int&p) {
    
    const char* ar_R_2 = ar_R;  
    stack <Info> st;
    //Цикл бежит по указателю (арифметика указателей)
    for (; *ar_R; ++ar_R) {
        
        switch (*ar_R) {
        case '(':
        case '[':
        case '{':
            //При Push происходит арифметика указателей, указывает туда же но смещается на один вперёд
            st.push(Info(*ar_R, static_cast<int>(ar_R - ar_R_2)));
            break;             
        case ')':
        case ']':
        case '}':
            //Если пуст? или Не равен "(" и ")" началу и концу
            //То есть провера скобок, (проверяется Верхний элемент и указатель то есть закрывающейся элемент)
            if (st.empty() || !beg_ENd(st.top().Ch, *ar_R)) {
                p = static_cast<int>(ar_R - ar_R_2);// Если условие верно то переключается и передаёт позицию(арифметика указателей)
                return false;
            }           
             st.pop(); //Удаление элемента из стека                              
             break;
        }
    }
     
    //если результат пуст и не равен указателю на массив (то есть пусто по указателю)
    bool result = st.empty();
    for (; !st.empty(); st.pop()) 
        p = st.top().pos; //передаёт позицию верха стека
    
    //делает возвращение если не равен указателю и результат равен true
        return !*ar_R && result; 
};
//Динамически выделяю память и передаю параметры на проверку
 void creaTNewArr(const char * Arr) {
    int len = strlen(Arr); 
    int p;
    
    char* newArrayChar= { nullptr };

        newArrayChar= new char[len+1];   
    for (int i = 0; i <=len; i++) {      
        newArrayChar[i] = Arr[i];
       
    }
    Arr = newArrayChar;
   

    if (CheckChar_A(Arr, p)) {
        cout << "All Right!!!" << endl;
   }
    else {
        cout << "Wrong: " << Arr + p << ";";
    }
 };

 void setInput_Char_Arr_User() {
     cout << "Input new user string: ";
     char userInput[50];
     cin.getline(userInput,50);
     creaTNewArr(userInput);   
 }

int main()
{
    
    setInput_Char_Arr_User();  
    
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
