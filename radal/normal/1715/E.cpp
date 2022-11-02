#include <bits/stdc++.h>
#pragma GCC target("sse,sse2")
#pragma GCC optimize("unroll-loops,O3")
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
constexpr int N = 1e5+20,mod = 1e9+7,inf = 1e9+10;
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
        k /= 2;
    } 
    return z; 
}
vector<pll> adj[N];
ll dp[N][21];
int opt[N][21];
int n,m,k;


void dij(int j){
    priority_queue<pair<ll,int> > pq;
    rep(i,1,n+1) pq.push({-dp[i][j],i});
    while (!pq.empty()){
        auto p = pq.top();
        pq.pop();
        int v = p.Y;
        if (dp[v][j] != -p.X) continue;
        for (auto u : adj[v]){
            if (dp[u.X][j] > dp[v][j]+u.Y){
                dp[u.X][j] = dp[v][j]+u.Y;
                pq.push({-dp[u.X][j],u.X});
            }
        }
    }
}

ll pw(int x){
    return 1ll*x*x;
}

void f(int l,int r,int s,int e,int j){
    if (r == l) return;
    int m = (l+r) >> 1;
    rep(i,s,e){
        if (dp[m][j] > dp[i][j-1]+pw(i-m)){
            opt[m][j] = i;
            dp[m][j] = dp[i][j-1]+pw(i-m);
        }
    }
    if (r-l == 1) return;
    f(l,m,s,opt[m][j]+1,j);
    f(m,r,opt[m][j],e,j);
}
void solve(){
    memset(dp,63,sizeof dp);
    cin >> n >> m >> k;
    rep(i,0,m){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    dp[1][0] = 0;
    dij(0);
    rep(j,1,k+1){
        f(1,n+1,1,n+1,j);
        rep(i,1,n+1){
            dp[i][j] = min(dp[i][j],dp[i][j-1]);
        }
        dij(j);
    }
    rep(i,1,n+1) cout << dp[i][k] << ' ';
}
int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
//    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}