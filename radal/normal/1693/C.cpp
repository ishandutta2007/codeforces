#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse4,avx2")
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
constexpr int N = 3e5+20,mod = 998244353,inf = 1e9+10;
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
vector<int> out[N],in[N];
int cost[N],t[N],n,d[N];
bool vis[N];
void dij(){
    cost[n] = 0;
    set<pll> st;
    st.insert({0,n});
    while (!st.empty()){
        pll p = *(st.begin());
        st.erase(p);
        vis[p.Y] = 1;
        int v = p.Y;
        for (int u : in[v]){
            if (vis[u]) continue;
            d[u]++;
            if (cost[u] > cost[v]+t[u]-d[u]+1){
                st.erase({cost[u],u});
                cost[u] = cost[v]+t[u]+1-d[u];
                st.insert({cost[u],u});
            }
        }
    }
}
inline void solve(){
    memset(cost,63,sizeof cost);
    int m;
    cin >> n >> m;
    rep(i,0,m){
        int u,v;
        cin >> u >> v;
        out[u].pb(v);
        in[v].pb(u);
    }
    rep(i,1,n) t[i] = out[i].size();
    dij();
    cout << cost[1];
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    //cin >> T;
    while (T--){
        solve();
    }
    return 0;
}