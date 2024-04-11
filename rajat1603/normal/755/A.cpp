#include "bits/stdc++.h"
using namespace std;
int n;
bool prime(int num){
    if(num < 2){
        return 0;
    }
    for(int i = 2 ; i * i <= num ; ++i){
        if(num % i == 0){
            return 0;
        }
    }
    return 1;
}
int main(){
    cin >> n;
    for(int m = 1 ; m <= 1000 ; ++m){
        if(!prime(n * m + 1)){
            cout << m << endl;
            return 0;
        }
    }
}