#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
string str[N];
int n;
int main(){
    cin >> n;
    for(int i = 0 ; i < n ; ++i){
        cin >> str[i];
    }
    for(int i = 0 ; i < n ; ++i){
        if(str[i][0] == 'O' && str[i][1] == 'O'){
            str[i][0] = '+';
            str[i][1] = '+';
            cout << "YES\n";
            for(int j = 0 ; j < n ; ++j){
                cout << str[j] << endl;
            }
            return 0;
        }
        if(str[i][3] == 'O' && str[i][4] == 'O'){
            str[i][3] = '+';
            str[i][4] = '+';
            cout << "YES\n";
            for(int j = 0 ; j < n ; ++j){
                cout << str[j] << endl;
            }
            return 0;
        }
    }
    cout << "NO\n";
}