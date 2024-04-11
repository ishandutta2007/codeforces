#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse4,avx2")
//#pragma GCC optimize("unroll-loops,O2")
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
constexpr int N = 3e3+10,mod = 1e9+7,inf = 1e9+10;
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
int dp[N][N],n,d,cal[N],c[N][N],inv[N];
vector<int> adj[N];
void dfs(int v){
    for (int u : adj[v]){
        dfs(u);
    }
    dp[v][1] = 1;
    rep(j,2,n+1){
        int z = 1;
        for (int u : adj[v]){
            z = 1ll*z*dp[u][j]%mod;
        }
        dp[v][j] = mkay(dp[v][j-1],z);
    }
}
int cr(int r,int d){
    if (r > d) return 0;
    int ans = 1;
    repr(i,d,d-r+1) ans = 1ll*ans*i%mod;
    rep(i,1,r+1) ans = 1ll*ans*inv[i]%mod;
    return ans;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n >> d;
    rep(i,2,n+1){
        int x;
        cin >> x;
        adj[x].pb(i);
    }
    dfs(1);
    rep(i,0,n+1){
        c[0][i] = 1;
        inv[i] = poww(i,mod-2);
    }
    rep(i,1,n+1) rep(j,i,n+1) c[i][j] = mkay(c[i][j-1],c[i-1][j-1]);
    int ans = 0;
    rep(i,1,n+1){
        cal[i] = dp[1][i];
        rep(j,1,i)
            cal[i] = mkay(cal[i],-1ll*cal[j]*c[j][i]%mod);
        ans = mkay(ans,1ll*cal[i]*cr(i,d)%mod);
    }
    cout << ans;
}