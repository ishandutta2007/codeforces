#include "bits/stdc++.h"
using namespace std;
const int N = 100;
const int M = 20;
int n;
int arr[N];
int m;
char str[M + 2];
int team[M];
int dp[1 << M];
void solve(){
    for(int mask = (1 << m) - 1 ; mask >= 0 ; --mask){
        int pos = __builtin_popcount(mask);
        if(pos == m){
            dp[mask] = 0;
        }
        else{
            int res;
            int tm = team[pos];
            char c = str[pos];
            if(tm == 1){
                res = -1e9;
            }
            else{
                res = 1e9;
            }
            for(int i = 0 ; i < m ; ++i){
                if(!(mask & (1 << i))){
                    if(tm == 1){
                        if(c == 'p'){
                            res = max(res , dp[mask | (1 << i)] + arr[i]);
                        }
                        else{
                            res = max(res , dp[mask | (1 << i)]);   
                        }
                    }
                    else{
                        if(c == 'p'){
                            res = min(res , dp[mask | (1 << i)] - arr[i]);
                        }
                        else{
                            res = min(res , dp[mask | (1 << i)]);
                        }
                    }
                }
            }
            dp[mask] = res;
        }
    }
}
int main(){
    scanf("%d" , &n);
    for(int i = 0 ; i < n ; ++i){
        scanf("%d" , arr + i);
    }
    sort(arr , arr + n);
    reverse(arr , arr + n);
    scanf("%d" , &m);
    for(int i = 0 ; i < m ; ++i){
        scanf("%s %d" , str + i , team + i);
    }
    solve();
    printf("%d\n" , dp[0]);
}