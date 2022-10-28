#include "bits/stdc++.h"
using namespace std;
int a , b , cur;
int main(){
    cin >> a >> b;
    cur = 1;
    while(1){
        if(a < cur){
            cout << "Vladik\n";
            break;
        }
        a -= cur;
        ++cur;
        if(b < cur){
            cout << "Valera\n";
            break;
        }
        b -= cur;
        ++cur;
    }
}