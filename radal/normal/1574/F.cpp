#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,avx2")
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
constexpr ll N = 3e5+10,mod = 998244353,inf = 1e9+10;
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
vector<int> a[N],in[N],out[N],ve;
int sz,dp[N];
bool bad[N],vis[N];
void rlx(int v){
    bad[v] = 1;
    for (int u : out[v]) if (!bad[u]) rlx(u);
    for (int u : in[v]) if (!bad[u]) rlx(u);
}
void dfs(int v){
    sz++;
    for (int u : out[v]) dfs(u);
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    rep(i,0,n){
        int c;
        cin >> c;
        a[i].resize(c);
        bool fl = 0;
        rep(j,0,c) cin >> a[i][j];
        rep(j,0,c){
            if (vis[a[i][j]]){
                fl = 1;
                break;
            }
            vis[a[i][j]] = 1;
        }
        rep(j,0,c){
            vis[a[i][j]] = 0;
            if (j){
                in[a[i][j]].pb(a[i][j-1]);
                out[a[i][j-1]].pb(a[i][j]);
            }
            if (fl) bad[a[i][j]] = 1;
        }
    }
    rep(i,1,k+1){
        sort(all(in[i]));
        sort(all(out[i]));
        in[i].resize(unique(all(in[i]))-in[i].begin());
        out[i].resize(unique(all(out[i]))-out[i].begin());
    }
    rep(i,1,k+1){
        if (bad[i] || in[i].size() > 1 || out[i].size() > 1){
            rlx(i);
        }
    }
    rep(i,1,k+1){
        if (!bad[i] && in[i].empty()){
            sz = 0;
            dfs(i);
            ve.pb(sz);
        }
    }
    if (ve.empty()){
        cout << 0;
        return 0;
    }
    sort(all(ve));
    vector<pll> fu;
    sz = ve.size();
    rep(i,0,sz){
        int cnt = 0;
        int j = i;
        while (j < sz && ve[j] == ve[i]){
            cnt++;
            j++;
        }
        i = j-1;
        debug(ve[i]);
        fu.pb({ve[i],cnt});
    }
    dp[0] = 1;
    rep(i,1,m+1){
        for (pll p : fu){
            if (p.X > i) break;
            dp[i] = mkay(dp[i],1ll*p.Y*dp[i-p.X]%mod);
        }
    }
    cout << dp[m];
    return 0;
}