#include "bits/stdc++.h"
using namespace std;
const int N = 105;
const long long inf = 1e15;
int n , m , k;
int arr[N];
int cost[N][N];
long long dp[N][N][N];
long long solve(int pos , int last , int kleft){
    if(kleft < 0){
        return inf;
    }
    if(pos > n){
        if(kleft){
            return inf;
        }
        return 0;
    }
    if(dp[pos][last][kleft] != -1){
        return dp[pos][last][kleft];
    }
    long long res = inf;
    if(arr[pos]){
        if(last == arr[pos]){
            res = min(res , solve(pos + 1 , arr[pos] , kleft));
        }
        else{
            res = min(res , solve(pos + 1 , arr[pos] , kleft - 1));
        }
    }
    else{
        for(int i = 1 ; i <= m ; ++i){
            if(last == i){
                res = min(res , solve(pos + 1 , i , kleft) + cost[pos][i]);
            }
            else{
                res = min(res , solve(pos + 1 , i , kleft - 1) + cost[pos][i]);
            }
        }
    }
    return dp[pos][last][kleft] = res;
}
int main(){
    scanf("%d %d %d" , &n , &m , &k);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            scanf("%d" , &cost[i][j]);
        }
    }
    memset(dp , -1 , sizeof(dp));
    long long ans = inf;
    if(arr[1]){
        ans = min(ans , solve(2 , arr[1] , k - 1));
    }
    else{
        for(int i = 1 ; i <= m ; ++i){
            ans = min(ans , solve(2 , i , k - 1) + cost[1][i]);
        }
    }
    if(ans >= inf){
        ans = -1;
    }
    printf("%lld\n" , ans);
}