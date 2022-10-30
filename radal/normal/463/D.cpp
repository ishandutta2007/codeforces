#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef pair <ll,ll>  pll;
const ll N = 1e3+30,inf = 1e10,mod=1e9+7;
vector<ll> ve[N];
int a[N][5];
bool st[N][N],visited[N];
ll dp[N];
ll dfs(ll v){
    ll ans=0;
    for (int u : ve[v]){
        if (dp[u] == -1) dfs(u);
        ans = max(ans,dp[u]);
    }
    dp[v] = ans+1;
    return ans+1;
}
int main(){
    memset(dp,-1,sizeof dp);
    ll n,k;
    cin >> n >> k;
    rep (i,0,k){
        rep(j,0,n){
            cin >> a[j][i];
        }
    }
    rep(i,0,k){
        rep(j,0,n){
            rep(p,j,n){
                st[a[p][i]][a[j][i]] = 1;
            }
        }
    }
    rep (i,1,n+1){
        rep(j,1,n+1){
            if (!st[i][j]){
                ve[i].pb(j);
           //     debug(i);
         //       debug(j);
            }
        }
    }
    rep (i,1,n+1){
        if (!visited[i]){
            dfs(i);
            //debug(i);
        }
    }
    //dfs(1);
    ll ans=0;
    rep(i,1,n+1) ans = max(ans,dp[i]);
    cout << ans;
    return 0;
}