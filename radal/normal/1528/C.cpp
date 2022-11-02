#include <bits/stdc++.h>
#pragma GCC optimize("O3")
//#pragma GCC target("avx2,fma")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
const long long int N = 3e5+20,mod = 1e9+7,inf = 1e18+10,sq = 300,maxm= 700+2;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}

inline int poww(int a,int k){
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k >>= 1;
    }
    return z;
}
int n,t,tin[N],tout[N],ans;
vector<int> adj[N][2];
set<pll> st;
void dfs(int v){
    tin[v] = t;
    t++;
    for (int u : adj[v][1]) dfs(u);
    tout[v] = t;
    t++;
}
void dfs2(int v){
    int w = -1;
    auto it = st.lower_bound({tin[v],v});
    if (it == st.end() || it->X > tout[v]){
        st.insert({tin[v],v});
        it = st.lower_bound({tin[v],v});
        if (it != st.begin()){
            it--;
            if (tout[it->Y] > tout[v]){
                w = it->Y;
                st.erase(it);
            }
        }
    }
    ans = max(ans,int(st.size()));
    for (int u : adj[v][0]) dfs2(u);
    st.erase({tin[v],v});
    if (w != -1) st.insert({tin[w],w});
}
inline void solve(){
    cin >> n;
    rep(i,1,n+1){
        adj[i][0].clear();
        adj[i][1].clear();
    }
    rep(i,2,n+1){
        int v;
        cin >> v;
        adj[v][0].pb(i);
    }
    rep(i,2,n+1){
        int v;
        cin >> v;
        adj[v][1].pb(i);
    }
    t = 0;
    dfs(1);
    ans = 0;
    st.clear();
    dfs2(1);
    cout << ans << endl;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}