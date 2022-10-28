#include "bits/stdc++.h"
using namespace std;
int s1 = 0 , s2 = 0 , n , inp;
int main(){
    for(int i = 0 ; i < 3 ; ++i){
        cin >> inp;
        s1 += inp;
    }
    for(int i = 0 ; i < 3 ; ++i){
        cin >> inp;
        s2 += inp;
    }
    cin >> n;
    while(s1 > 0){
        s1 -= 5;
        --n;
    }
    while(s2 > 0){
        s2 -= 10;
        --n;
    }
    if(n >= 0){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}