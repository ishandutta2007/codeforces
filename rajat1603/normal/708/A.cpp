#include "bits/stdc++.h"
using namespace std;
string str;
int main(){
    cin >> str;
    int n = str.size();
    for(int i = 0 ; i < n ; ++i){
        if(str[i] != 'a'){
            for(int j = i ; j < n ; ++j){
                if(str[j] == 'a'){
                    break;
                }
                --str[j];
            }
            cout << str << endl;
            return 0;
        }
    }
    str[n - 1] = 'z';
    cout << str;
}