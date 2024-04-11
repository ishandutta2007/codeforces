//saadddd wrong code

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
constexpr int N = 2e5+20,mod = 1e9+7,inf = 1e9+10;
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
int pr[N],a[N],ans;
vector<int> adj[N];
set<int> st[N];
void dfs(int v,int p){
    pr[v] = a[v]^pr[p];
    bool f = 0;
    st[v].insert(pr[v]);
    for (int u : adj[v]){
        if (u == p) continue;
        dfs(u,v);
        if (st[u].size() > st[v].size()) swap(st[u],st[v]);
        if (!f) for (int x : st[u]) if (st[v].find(x^a[v]) != st[v].end()){
            f = 1;
            break;
        }
        while (!st[u].empty()){
            int x = (*st[u].begin());
            st[u].erase(st[u].begin());
            st[v].insert(x);
        }
    }
    ans += f;
    if (f) st[v].clear();
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    rep(i,1,n+1) cin >> a[i];
    rep(i,1,n){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,0);
    cout << ans;
    return 0;
}