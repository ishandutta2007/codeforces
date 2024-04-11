#include "bits/stdc++.h"
using namespace std;
const int M = 1e5 + 5;
const int N = 333;
const int mod = 1e9 + 7;
int n , m , x;
int dp[N * M + 4 * M];
int solve(int nleft , int pos , int op){
    if(pos > m){
        return !(nleft || op);
    }
    int mem = nleft * n * m + nleft * m + nleft * n + pos * n + pos + op;
    if(dp[mem] != -1){
        return dp[mem];
    }
    unsigned res = 0;
    if(pos != x){
        res += solve(nleft , pos + 1 , op);
    }
    if(nleft){
        res += solve(nleft - 1 , pos + 1 , op + 1);
    }
    if(op && (pos != x)){
        res += solve(nleft , pos + 1 , op - 1);
    }
    if(nleft){
        res += solve(nleft - 1 , pos + 1 , op);
    }
    res %= mod;
    return dp[mem] = res;
}
//[0 , n] , [1 , m] , [0 , n]
//amn + am + an + bn + b + c
int main(){
    cin >> n >> m >> x;
    if(n > m){
        cout << "0\n";
        return 0;
    }
    memset(dp , -1 , sizeof(dp));
    int ans = solve(n , 1 , 0);
    for(int i = 1 ; i <= n ; ++i){
        ans = (1LL * ans * i) % mod;
    }
    cout << ans << endl;
}