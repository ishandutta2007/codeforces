#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,avx2")
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
constexpr int N = 2e5+10,mod = 1e9+7,inf = 1e9+10;
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
int n,k;
int mark[N],sz[N];
vector<int> adj[N],ve[N];

void pre(int v,int p){
    sz[v] = mark[v];
    for (int u : adj[v]){
        if (u == p) continue;
        pre(u,v);
        sz[v] += sz[u];
    }
}

int cent(int v,int p){
    for (int u : adj[v]){
        if (u == p) continue;
        if (sz[u] > k) return cent(u,v);
    }
    return v;
}
void dfs(int v,int p,int r){
    if (mark[v]) ve[r].pb(v);
    for (int u : adj[v]){
        if (u != p)
            dfs(u,v,r);
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    rep(i,1,n){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    rep(i,0,2*k){
        int c;
        cin >> c;
        mark[c] = 1;
    }
    pre(1,0);
    int x = cent(1,0);
    for (int u : adj[x]) dfs(u,x,u);
    set<pll> st;
    if (mark[x]){
        ve[x].pb(x);
        st.insert({1,x});
    }
    for (int u : adj[x]) if (!ve[u].empty()) st.insert({ve[u].size(),u});
    vector<pll> ans;
    rep(i,0,k){
        pll p = (*st.rbegin());
        st.erase(p);
        pll p2 = (*st.rbegin());
        st.erase(p2);
        int u = p.Y,v = p2.Y;
        ans.pb({ve[u].back(),ve[v].back()});
        ve[u].pop_back();
        ve[v].pop_back();
        if (!ve[u].empty()) st.insert({ve[u].size(),u});
        if (!ve[v].empty()) st.insert({ve[v].size(),v});
    }
    cout << 1 << endl;
    cout << x << endl;
    for (pll p : ans) cout << p.X << ' ' << p.Y << ' ' << x << endl;
    return 0;
}