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
const long long int N = 1e5+20,mod = 1e9+7,inf = 1e18+10,sq = 300,maxm= (1 << 27);
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
int sz[N],n,ans[N],h[N];
ll sum[N];
vector<int> adj[N];
vector<int> ve[N];
void dfs(int v,int p){
    sz[v] = 1;
    for(int u : adj[v]) if (u != p){
        dfs(u,v);
        sz[v] += sz[u];
    }
}
int cent(int v,int p){
    for (int u : adj[v]){
        if (u != p && sz[u]*2 > n){
            return cent(u,v);
        }
    }
    return v;
}
void dfs2(int v,int p,int w){
    ve[w].pb(v);
    sum[w] += h[v];
    for (int u : adj[v]) if (p != u){
        h[u] = h[v]+1;
        dfs2(u,v,w);
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i,1,n){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,0);
    int v = cent(1,0);
    dfs(v,0);
    set<pll> st;
    ll s = 0;
    for (int u : adj[v]){
        h[u] = 1;
        dfs2(u,v,u);
        st.insert({sz[u],u});
        s += sum[u];
    }
    cout << 2*s << endl;
    int m = n;
    while (n > 3){
        auto it = st.rbegin(),it2 = it++;
        auto p1 = (*it), p2 = (*it2);
        it--;
        st.erase(p1);
        st.erase(p2);
        n -= 2;
        int u = ve[p1.Y].back(),u2 = ve[p2.Y].back();
        ve[p1.Y].pop_back();
        ve[p2.Y].pop_back();
        ans[u] = u2;
        ans[u2] = u;
        st.insert({p1.X-1,p1.Y});
        st.insert({p2.X-1,p2.Y});
    }
    auto it = st.rbegin();
    //
    if (n == 2){
        ans[v] = ve[it->Y].back();
        ans[ve[it->Y].back()] = v;
    }
    else{
        auto it2 = it;
        it2++;
        int u = ve[it->Y].back(),w = ve[it2->Y].back();
        ans[v] = u;
        ans[u] = w;
        ans[w] = v;
    }
    rep(i,1,m+1) cout << ans[i] << ' ';
}