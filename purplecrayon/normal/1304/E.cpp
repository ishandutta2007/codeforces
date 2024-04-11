#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void fsc(int &x){
    register int c;
    x = 0; c=getchar();
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1)+(x<<3)+c-48;
}
void read(){}
template <typename T, typename... Types> 
void read(T& var1, Types&... var2) { 
    fsc(var1);
    read(var2...) ; 
} 

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e5+10, MAXM = 50+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 2e5+10, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB), MAXP = 2e5+10;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int n, depth[MAXN], anc[MAXN][MAXL];
vector<int> adj[MAXN];

void dfs(int c=0, int p=-1, int d=0){
    depth[c]=d; anc[c][0]=p;
    for (int k=1; k < MAXL; k++) anc[c][k] = (anc[c][k-1]!=-1?anc[anc[c][k-1]][k-1]:-1);
    for (auto nxt : adj[c]) if (nxt != p) dfs(nxt, c, d+1);
}
int lca(int u, int v) {
	if(depth[u] < depth[v]) swap(u, v);
	for(int i=MAXL-1; i >= 0; --i) if (depth[u]-(1<<i) >= depth[v]) u = anc[u][i];
	if(u == v) return u;
	for(int i=MAXL-1; i >= 0; --i) if(anc[u][i] != anc[v][i]) u=anc[u][i], v=anc[v][i];
	return anc[u][0];
}
int dist(int a, int b){ return depth[a]+depth[b]-2*depth[lca(a, b)]; }
void solve(){
    read(n);
    for (int i = 0; i < n-1; i++){
        int a, b; read(a, b), --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    dfs();
    int q; read(q);
    auto works = [&](int d, int k) -> bool {
        return d <= k && ((d&1) == (k&1));
    };
    while (q--){
        int x, y, a, b, k; read(x, y, a, b, k), --x, --y, --a, --b;
        int d1 = dist(a, b), d2 = dist(a, x)+1+dist(b, y), d3 = dist(a, y)+1+dist(b, x);
        cout << (works(d1, k)||works(d2, k)||works(d3, k)?yes:no);
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;// cin >> t;
    while (t--) solve();
}