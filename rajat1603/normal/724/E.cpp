#include "bits/stdc++.h"
using namespace std;
const int N = 1e4 + 4;
int n , c;
int p[N];
int s[N];
long long dp[2][N];
int main(){
    scanf("%d %d" , &n , &c);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , p + i);
    }
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , s + i);
    }
    for(int pos = n ; pos >= 1 ; --pos){
        for(int up = 0 ; up < n ; ++up){
            dp[pos & 1][up] = min(dp[!(pos & 1)][up + 1] + s[pos] , dp[!(pos & 1)][up] + 1LL * c * up + p[pos]);
        }
    }
    printf("%lld\n" , dp[1][0]);
}