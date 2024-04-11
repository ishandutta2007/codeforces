#include "bits/stdc++.h"
using namespace std;
string str;
int main(){
    cin >> str;
    str = "00" + str;
    for(int i = 0 ; i < str.size() ; ++i){
        for(int j = i + 1 ; j < str.size() ; ++j){
            for(int k = j + 1 ; k < str.size() ; ++k){
                int num = (str[i] - '0') * 100 + (str[j] - '0') * 10 + str[k] - '0';
                if(!(num & 7)){
                    cout << "YES\n" << num;
                    return 0;
                }
            }
        }
    }
    cout << "NO";
}