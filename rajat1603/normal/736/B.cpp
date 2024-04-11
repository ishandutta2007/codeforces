#include "bits/stdc++.h"
using namespace std;
int n;
bool prime(int n){
    for(int i = 2 ; i * i <= n ; ++i){
        if(n % i == 0){
            return 0;
        }
    }
    return 1;
}
int main(){
    cin >> n;
    if(prime(n)){
        cout << 1 << endl;
    }
    else{
        if(n & 1){
            if(prime(n - 2)){
                cout << 2 << endl;
            }
            else{
                cout << 3 << endl;
            }
        }
        else{
            cout << 2 << endl;
        }
    }
}