#include "bits/stdc++.h"
using namespace std;
string a , b;
int main(){
    cin >> a >> b;
    if(a.size() != b.size()){
        cout << "NO";
    }
    else{
        if(a == b){
            cout << "YES";
        }
        else{
            bool A = 0;
            for(int i = 0 ; i < a.size() ; ++i){
                A |= a[i] - '0';
            }
            bool B = 0;
            for(int i = 0 ; i < b.size() ; ++i){
                B |= b[i] - '0';
            }
            A &= B;
            if(A){
                cout << "YES";
            }
            else{
                cout << "NO";
            }
        }
    }
}