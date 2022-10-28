#include "bits/stdc++.h"
using namespace std;
string str;
int main(){
    cin >> str;
    for(int i = 0 ; i < str.size() - 1 ; ++i){
        if(str[i] == 'A' && str[i +1 ] == 'B'){
            str[i] = 'F';
            str[i + 1] = 'U';
            for(int i = 0 ; i < str.size() - 1 ; ++i){
                if(str[i] == 'B' && str[i + 1] == 'A'){
                    cout << "YES";
                    return 0;
                }
            }
            str[i] = 'A';
            str[i + 1] = 'B';
            break;
        }
    }
    for(int i = 0 ; i < str.size() - 1 ; ++i){
        if(str[i] == 'B' && str[i +1 ] == 'A'){
            str[i] = 'F';
            str[i + 1] = 'U';
            for(int i = 0 ; i < str.size() - 1 ; ++i){
                if(str[i] == 'A' && str[i + 1] == 'B'){
                    cout << "YES";
                    return 0;
                }
            }
            cout << "NO";
            return 0;
        }
    }
    cout << "NO";
}