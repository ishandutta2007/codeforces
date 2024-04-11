#include "bits/stdc++.h"
using namespace std;
int n;
int main(){
    cin >> n;
    for(int i = 1 ; i + i < n ; ++i){
        int cnt = i + i - 1;
        int extra = n - cnt;
        extra >>= 1;
        for(int i = 1 ; i <= extra ; ++i){
            cout << "*";
        }
        for(int i = 1 ; i <= cnt ; ++i){
            cout << "D";
        }
        for(int i = 1 ; i <= extra ; ++i){
            cout << "*";
        }
        cout << "\n";
    }
    for(int i = 1 ; i <= n ; ++i){
        cout << "D";
    }
    cout << "\n";
    for(int i = (n >> 1) ; i ; --i){
        int cnt = i + i - 1;
        int extra = n - cnt;
        extra >>= 1;
        for(int i = 1 ; i <= extra ; ++i){
            cout << "*";
        }
        for(int i = 1 ; i <= cnt ; ++i){
            cout << "D";
        }
        for(int i = 1 ; i <= extra ; ++i){
            cout << "*";
        }
        cout << "\n";
    }
}