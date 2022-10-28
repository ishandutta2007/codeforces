#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
const int mod = 1e9 + 7;
int t , k;
int n , m;
char l[N];
char r[N];
int dp[N][N][2];
int solve(int len , int last , bool ok){
    if(len < 1){
        return ok;
    }
    last = min(last , k + 1);
    if(dp[len][last][ok] != -1){
        return dp[len][last][ok];
    }
    return dp[len][last][ok] = (8LL * solve(len - 1 , last + 1 , ok) + 2LL * solve(len - 1 , 1 , ok | (last <= k))) % mod;
}
int solve(char str[] , int len , bool inc){
    int last = k + 1;
    bool ok = 0;
    int res = 0;
    for(int i = 0 ; i < len ; ++i){
        for(int j = 0 ; j < str[i] - '0' ; ++j){
            if(j == 4 || j == 7){
                res += solve(len - i - 1 , 1 , ok | (last <= k));
            }
            else{
                res += solve(len - i - 1 , last + 1 , ok);
            }
            res -= (res >= mod) * mod;
        }
        if(str[i] == '4' || str[i] == '7'){
            if(last <= k){
                ok = 1;
            }
            last = 0;
        }
        ++last;
    }
    return res + ok * inc;
}
int main(){
    memset(dp , -1 , sizeof(dp));
    scanf("%d %d" , &t , &k);
    while(t--){
        scanf("%s %s" , l , r);
        n = strlen(l);
        m = strlen(r);
        printf("%d\n" , (solve(r , m , 1) - solve(l , n , 0) + mod) % mod);
    }
}