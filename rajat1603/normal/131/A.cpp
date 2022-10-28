#include "bits/stdc++.h"
using namespace std;
string str;
int n;
bool ok = 1;
int main(){
    cin >> str;
    n = str.size();
    str = " " + str;
    for(int i = 2 ; i <= n ; ++i){
        ok &= isupper(str[i]);
    }
    if(ok){
        for(int i = 2 ; i <= n ; ++i){
            str[i] = tolower(str[i]);
        }
        if(isupper(str[1])){
            str[1] = tolower(str[1]);
        }
        else{
            str[1] = toupper(str[1]);
        }
    }       
    cout << str;
}