#include "bits/stdc++.h"
using namespace std;
const int N = 105;
int n;
string str[N];
int ans = 0;
int main(){
    cin >> n;
    for(int i = 0 ; i < n ; ++i){
        cin >> str[i];
    }
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j){
            for(int k = 0 ; k < j ; ++k){
                ans += (str[i][j] == str[i][k]) && (str[i][j] == 'C');
            }
        }
    }
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < n ; ++j){
            for(int k = 0 ; k < j ; ++k){
                ans += (str[j][i] == str[k][i]) && (str[j][i] == 'C');
            }
        }
    }
    cout << ans;
}