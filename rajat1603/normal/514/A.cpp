#include "bits/stdc++.h"
using namespace std;
string str;
int main(){
    cin >> str;
    for(int i = 0 ; i < str.size() ; ++i){
        if(i){
            if(str[i] >= '5'){
                str[i] = '9' - str[i] + '0';
            }
        }
        else{
            if(str[i] >= '5' && str[i] <= '8'){
                str[i] = '9' - str[i] + '0';
            }
        }
    }
    cout << str;
}