#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse4,avx2")
#pragma GCC optimize("unroll-loops,O2")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define all(x) (x).begin() , (x).end()
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
constexpr int N = 1e2+20,mod = 1e9+7,inf = 1e9+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k >>= 1;
    } 
    return z; 
}
vector<int> adj[N];
int dp[N][N][N],sz[N],tmp[N][N],inv[N],c[N][N],ans[N];
void dfs(int v,int p){
    sz[v] = 1;
    dp[v][0][1] = 1;
    for (int u : adj[v]){
        if (u == p) continue;
        dfs(u,v);
        repr(k,sz[v]-1,0){
            repr(j,sz[v],1){
                repr(k2,sz[u]-1,0){
                    repr(i,sz[u],1){
                        tmp[k+k2][j] = mkay(tmp[k+k2][j],1ll*dp[v][k][j]*dp[u][k2][i]%mod);
                        tmp[k+k2+1][j+i] = mkay(tmp[k+k2+1][j+i],1ll*dp[v][k][j]*dp[u][k2][i]%mod*(i+j)%mod*inv[i]%mod*inv[j]%mod);
                    }
                }
            }
        }
        sz[v] += sz[u];
        rep(k,0,sz[v]){
            rep(j,1,sz[v]+1){
                dp[v][k][j] = tmp[k][j];
                tmp[k][j]= 0;
            }
        }
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    rep(i,1,n){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    c[0][0] = 1;
    rep(i,1,n+1){
        inv[i] = poww(i,mod-2);
        c[0][i] = 1;
    }
    rep(i,1,n+1){
        rep(j,i,n+1)
            c[i][j] = mkay(c[i-1][j-1],c[i][j-1]);
    }
    dfs(1,0);
    ans[n-1] = 1;
    repr(k,n-2,0){
        rep(i,1,n+1){
            ans[k] = mkay(ans[k],dp[1][k][i]);
        }
        ans[k] = 1ll*ans[k]*poww(n,n-k-2)%mod;
        rep(i,k+1,n){
            ans[k] -= 1ll*ans[i]*c[k][i]%mod;
            if (ans[k] < 0) ans[k] += mod;
        }
    }
    rep(i,0,n) cout << ans[i] << ' ';

}