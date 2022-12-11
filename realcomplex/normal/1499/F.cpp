#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int>pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 5010;
const int MOD = 998244353;
int dp[N][N];
int sub[N];
int k;

vector<int> T[N];
int ndp[N];

void dfs(int u, int pp){
    sub[u]=1;
    for(auto x : T[u]){
        if(x==pp) continue;
        dfs(x,u);
    }
    dp[u][0]=1;
    for(auto x : T[u]){
        if(x == pp) continue;
        for(int j = 0 ; j <= k; j ++ ){
            ndp[j]=0;
        }
        for(int d0 = 0 ; d0 < sub[u]; d0 ++ ){
            for(int d1 = 0; d1 < sub[x] && d0 + d1 + 1 <= k; d1 ++ ){
                ndp[max(d0, d1 + 1)] += (dp[u][d0] * 1ll * dp[x][d1]) % MOD;
                ndp[max(d0, d1 + 1)] %= MOD;
            }
        }
        for(int i = 0 ; i <= min(sub[u], k); i ++ ){
            int mlt = 0;
            for(int j = 0; j <= min(sub[x], k); j ++ ){
                mlt += dp[x][j];
                mlt %= MOD;
            }
            ndp[i] += (dp[u][i] * 1ll * mlt) % MOD;
            ndp[i] %= MOD;
        }
        sub[u] += sub[x];
        for(int j = 0 ;j < sub[u] ; j ++ ){
            dp[u][j] = ndp[j];
        }
    }
}


int main(){
    fastIO;
    int n;
    cin >> n >> k;
    int u, v;
    for(int i = 1; i < n; i ++ ){
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    dfs(1, -1);
    int soln = 0;
    for(int i = 0 ; i <= k ; i ++ ){
        soln += dp[1][i];
        soln %= MOD;
    }
    cout << soln << "\n";
    return 0;
}