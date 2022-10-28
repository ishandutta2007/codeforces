#include "bits/stdc++.h"
using namespace std;
const int N = 55;
int n;
string str;
long long dp[N];
long long ans = 0;
int main(){
    cin >> n;
    cin >> str;
    str = " " + str;
    dp[1] = 1;
    for(int i = 2 ; i <= n ; ++i){
        dp[i] = 1;
        for(int j = 1 ; j < i ; ++j){
            dp[i] += dp[j];
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        if(str[i] == 'B'){
            ans += dp[i];
        }
    }
    cout << ans;
}