#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , m;
vector < int > v[N];
int a , b;
int dp[N];
long long ans = 0LL;
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d %d" , &a , &b);
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    for(int i = 1 ; i <= n ; ++i){
        dp[i] = 1;
        for(int next : v[i]){
            if(next < i){
                dp[i] = max(dp[i] , dp[next] + 1);
            }
        }
        ans = max(ans , 1LL * dp[i] * (int(v[i].size()) + 0LL));
    }
    printf("%lld\n" , ans);
}