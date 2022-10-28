#include "bits/stdc++.h"
using namespace std;
const int N = 80;
const int M = 20;
const int mod = 1e9 + 7;
int n;
char str[N];
int nxt[N];
int dp[N][1 << M];
int solve(int pos , int mask){
    if(dp[pos][mask] != -1){
        return dp[pos][mask];
    }
    int res = 0;
    if(mask > 0){
        if(((mask + 1) & (-(mask + 1))) == (mask + 1)){
            ++res;
        }
    }
    int num = 0;
    for(int i = nxt[pos] ; i < n ; ++i){
        num += num;
        num += str[i] - '0';
        if(num > 20){
            break;
        }
        res += solve(i + 1 , mask | (1 << (num - 1)));
        if(res >= mod){
            res -= mod;
        }
    }
    return dp[pos][mask] = res;
}
int main(){
    scanf("%d" , &n);
    scanf("%s" , str);
    int ans = 0;
    nxt[n] = n;
    for(int i = n - 1 ; i >= 0 ; --i){
        if(str[i] == '0'){
            nxt[i] = nxt[i + 1];
        }
        else{
            nxt[i] = i;
        }
    }
    memset(dp , -1 , sizeof(dp));
    for(int i = 0 ; i < n ; ++i){
        ans += solve(i , 0);
        ans %= mod;
    }
    printf("%d\n" , ans);
}