#include "bits/stdc++.h"
using namespace std;
int a1 , b1;
int a2 , b2;
int a3 , b3;
bool check(){
    if(max(a2 , a3) > a1 || max(b2 , b3) > b1){
        return 0;
    }
    if(a2 + a3 > a1 && b2 + b3 > b1){
        return 0;
    }
    return 1;
}
int main(){
    cin >> a1 >> b1;
    cin >> a2 >> b2;
    cin >> a3 >> b3;
    for(int i = 0 ; i < 2 ; ++i){
        for(int j = 0 ; j < 2 ; ++j){
            for(int k = 0 ; k < 2 ; ++k){
                if(check()){
                    cout << "YES";
                    return 0;
                }
                swap(a3 , b3);
            }
            swap(a2 , b2);
        }
        swap(a1 , b1);
    }
    cout << "NO";
}