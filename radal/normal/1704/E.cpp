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
constexpr int N = 1e3+20,mod = 998244353,inf = 1e9+10;
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
vector<int> adj[N],out[N];
int a[N],cnt[N][N],d[N],ti[N];
bool fl[N];
void solve(){
    int n,m;
    cin >> n >> m;
    ti[0] = 0;
    fl[0] = 0;
    rep(i,1,n+1){
        fl[i] = 0;
        cin >> a[i];
        ti[i] = 0;
        adj[i].clear();
        out[i].clear();
        d[i] = 0;
        rep(j,0,n+1) cnt[i][j] = 0;
    }
    rep(i,0,m){
        int u,v;
        cin >> u >> v;
        adj[v].pb(u);
        out[u].pb(v);
        d[u]++;
    }
    vector<int> to,ve;
    rep(i,1,n+1) if (!d[i]) ve.pb(i);
    while (!ve.empty()){
        int u = ve.back();
        ve.pop_back();
        to.pb(u);
        for (int v : adj[u]){
            d[v]--;
            if (!d[v]) ve.pb(v);
        }
    }
    cnt[to[0]][0] = 1;
    ti[0] = a[to[0]];
    if (ti[0] >= mod){
        ti[0] -= mod;
        fl[0] = 1;
    }
    rep(i,1,n){
        int v = to[i];
        rep(j,1,i+ 1){
            for(int u : out[v]) cnt[v][j] = mkay(cnt[v][j],cnt[u][j-1]);
            if (!fl[j] && ti[j]+1ll*cnt[v][j]*a[v] >= mod) fl[j] = 1;
            ti[j] = mkay(ti[j],1ll*cnt[v][j]*a[v]%mod);
        }
    }
    int ans = 0;
    int cur = 0;
    rep(i,0,n+1){
        if (fl[i] || i+cur+ti[i] >= mod){
            rep(j,i,n+1) cur = mkay(cur,ti[j]);
            cout << mkay(i,cur) << endl;
            return;
        }
        cur += ti[i]-1;
        if (cur < 0) cur = 0;
        else ans = max(ans,i+cur+1);
    }
    cout << ans << endl;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        solve();
    }
}