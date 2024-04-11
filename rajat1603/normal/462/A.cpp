#include "bits/stdc++.h"
using namespace std;
const int N = 105;
const int dx[4] = {0 , 1 , 0 , -1};
const int dy[4] = {1 , 0 , -1 , 0};
int n;
string str[N];
int main(){
    cin >> n;
    str[0] = "xx";
    str[n + 1] = "xx";
    for(int i = 1 ; i <= n ; ++i){
        cin >> str[i];
        str[0] += "x";
        str[n + 1] += "x";
        str[i] = "x" + str[i];
        str[i] += "x";
    }
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            int ctr = 0;
            for(int k = 0 ; k < 4 ; ++k){
                ctr += ((str[i + dx[k]][j + dy[k]]) == 'o');
            }
            if(ctr & 1){
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
}