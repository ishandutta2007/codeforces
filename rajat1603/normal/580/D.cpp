#include "bits/stdc++.h"
using namespace std;
const int N = 20;
int n , m , k;
int arr[N];
int cost[N][N];
long long dp[1 << N][N];
long long solve(int mask , int cnt , int last){
    if(cnt == m){
        return 0;
    }
    if(dp[mask][last] != -1){
        return dp[mask][last];
    }
    long long res = 0;
    for(int i = 1 ; i <= n ; ++i){
        if(!(mask & (1 << i))){
            res = max(res , solve(mask | (1 << i) , cnt + 1 , i) + arr[i] + cost[last][i]);
        }
    }
    return dp[mask][last] = res;
}
int main(){
    memset(dp , -1 , sizeof(dp));
    memset(cost , 0 , sizeof(cost));
    cin >> n >> m >> k;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
    }
    for(int i = 1 ; i <= k ; ++i){
        int a , b , c;
        cin >> a >> b >> c;
        cost[a][b] = c;
    }
    cout << solve(0 , 0 , 0);
}