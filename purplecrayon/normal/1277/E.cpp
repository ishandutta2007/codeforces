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
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int n, m, x, y, low[MAXN], depth[MAXN], sub[MAXN];
bool hasY[MAXN];
vector<int> ch[MAXN], adj[MAXN];
int dfs(int c, int d){
    depth[c] = d; low[c] = depth[c]; sub[c] = 1;
    hasY[c] = (c==y);
    for (auto nxt : adj[c]){
        if (depth[nxt] == -1){
            sub[c] += dfs(nxt, d+1); ch[c].push_back(nxt);
            hasY[c] |= hasY[nxt]; low[c] = min(low[c], low[nxt]);
        } else low[c] = min(low[c], depth[nxt]);
    }
    return sub[c];
}
void solve(){
    cin >> n >> m >> x >> y, --x, --y;
    for (int i = 0; i < n; i++) depth[i] = -1, hasY[i] = false, ch[i].clear(), adj[i].clear();
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    dfs(x, 0);
    ll ansx=0, ansy=0;
    for (auto nxt : ch[x]) if (!hasY[nxt]) ansx += sub[nxt];
    for (auto nxt : ch[y]) if (low[nxt] >= depth[y]) ansy += sub[nxt];
    cout << (ansx*ansy) << "\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while (t--) solve();
}