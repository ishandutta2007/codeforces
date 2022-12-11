#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1505;
const int M = N * N;
const int MOD = 998244353;
pii E[M];

int par[N];
int sz[N];
int ee[N];

int fin(int x){
    if(par[x]==x)return x;
    return par[x]=fin(par[x]);
}

vector<int> dp[N];

int main(){
    fastIO;
    int n;
    cin >> n;
    int a;
    for(int i = 1; i <= n ; i ++ ){
        par[i] = i;
        sz[i] = 1;
        dp[i] = {0, 1};
    }
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= n; j ++ ){
            cin >> a;
            if(i > j){
                E[a] = mp(i,j);
            }
        }
    }
    int pi, qi;
    for(int i = 1; i <= n * (n - 1) / 2; i ++ ){
        pi = E[i].fi;
        qi = E[i].se;
        pi = fin(pi);
        qi = fin(qi);
        if(pi == qi){
            ee[pi] ++ ;
        }
        else{
            par[pi] = qi;
            sz[qi] += sz[pi];
            ee[qi] += ee[pi] + 1;
            vector<int> tmp(sz[qi] + 1);
            for(int p = 0 ; p < dp[pi].size(); p ++ ){
                for(int q = 0 ; q < dp[qi].size(); q ++ ){
                    tmp[p + q] += (dp[pi][p] * 1ll * dp[qi][q]) % MOD;
                    if(tmp[p + q] >= MOD)
                        tmp[p + q] -= MOD;
                }
            }
            dp[qi] = tmp;
        }
        if(ee[qi] == sz[qi] * (sz[qi] - 1) / 2){
            dp[qi][1] ++ ;
            if(dp[qi][1] == MOD)
                dp[qi][1] %= MOD;
        }
    }
    for(int i = 1; i <= n; i ++ ){
        cout << dp[fin(1)][i] << " ";
    }
    cout << "\n";
    return 0;
}