#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
    string s;
    cin >> s;
    long long A[3];
    A[0] = 0;
    A[1] = 0;
    A[2] = 0;
    for (int i = 0; i < s.size(); ++i)
        ++A[s[i] - '0'];
    if (A[0] == 0){
        for (int i = 0; i < A[1]; ++i)
            cout << 1;
        for (int i = 0; i < A[2]; ++i)
            cout << 2;
    }else if (A[2] == 0){
        for (int i = 0; i < A[0]; ++i)
            cout << 0;
        for (int i = 0; i < A[1]; ++i)
            cout << 1;
    }else if (A[1] == 0){
        cout << s;
    }else{
        int a = 0, j;
        for (j = 0; j < s.size(); ++j){
            if (s[j] == '0')
                ++a;
            else if (s[j] == '2')
                break;
        }
        for (int i = 0; i < a; ++i)
            cout << 0;
        for (int i = 0; i < A[1]; ++i)
            cout << 1;
        for (; j < s.size(); ++j){
            if (s[j] != '1')
                cout << s[j];
        }
    }
    return 0;
}