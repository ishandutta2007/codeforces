#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC target("avx2,fma")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N = 1e5+20,mod = 998244353,inf = 1e9,sq = 400;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,int k){
    int c = 1;
    while (k){
        if (k&1) c = (1ll*c*n)%mod;
        n = (1ll*n*n)%mod;
        k >>= 1;
    }
    return c;
}
int h[N],par[N][20],tin[N],T,b[N];
vector<int> adj[N];
inline int lca(int u,int v){
    if (h[u] > h[v]) swap(u,v);
    repr(i,19,0){
        if (h[v]-h[u] >= (1 << i))
            v = par[v][i];
    }
    if (u == v) return v;
    repr(i,19,0){
        if (par[v][i] != par[u][i]){
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[v][0];
}
void dfs(int v,int p){
    tin[v] = T;
    par[v][0] = p;
    b[T] = v;
    T++;
    for (int u : adj[v]){
        if (u != p){
            h[u] = h[v]+1;
            dfs(u,v);
        }
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin >> n >> k;
    rep(i,1,n){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,0);
    rep(j,1,20)
        rep(i,1,n+1)
            par[i][j] = par[par[i][j-1]][j-1];
    int p1 = 1;
    k--;
    k *= 2;
    set<int> st;
    int ans = 1;
    int sum = 0;
    rep(i,1,n+1){
        st.insert(tin[i]);
        if (st.size() == 1){
            continue;
        }
        auto it = st.find(tin[i]);
        int v,u;
        auto it2 = it;
        it2++;
        if (it2 == st.end()){
            it2 = st.begin();
            v = b[(*it2)];
        }
        else{
            v = b[(*it2)];
        }
        if (it == st.begin()){
            auto it3 = st.rbegin();
            u = b[(*it3)];
        }
        else{
            it--;
            u = b[(*it)];
            it++;
        }
        int w = lca(i,v),w2 = lca(u,i),w3 = lca(u,v);
        sum += 2*h[i]-2*h[w]-2*h[w2]+2*h[w3];
        while (sum > k){
            it = st.find(tin[p1]);
            it2 = it;
            it2++;
            if (it2 == st.end()){
                it2 = st.begin();
                v = b[(*it2)];
            }
            else{
                v = b[(*it2)];
            }
            if (it == st.begin()){
                auto it4 = st.rbegin();
                u = b[(*it4)];
            }
            else{
                it--;
                u = b[(*it)];
                it++;
            }
            int w = lca(p1,v),w2 = lca(p1,u),w3 = lca(u,v);
            sum -= 2*(h[p1]-h[w]-h[w2]+h[w3]);
            st.erase(tin[p1]);
            p1++;
        }
        ans = max(ans,i-p1+1);
    }
    cout << ans;
}