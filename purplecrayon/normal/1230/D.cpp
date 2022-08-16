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
const int MAXN = 7e3+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MAXK = 17, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB), MOD = 1e9+7;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;

int n;
ll a[MAXN], s[MAXN];
vector<bool> vis;
bool isEdge(int i, int j){
    return (s[j]&s[i])==s[j];
}

struct scc {
    vector<int> g[MAXN], gr[MAXN], comp[MAXN], order;
    int who[MAXN], cc=0;
    bool used[MAXN];
    void dfs1 (int v) {
        used[v] = true;
        for (int nxt = 0; nxt < n; nxt++) if (nxt != v && isEdge(v, nxt) && !used[nxt]) dfs1(nxt);
        order.push_back(v);
    }
    void dfs2(int v) {
        used[v] = true; comp[cc].push_back(v); who[v] = cc;
        for (int nxt = 0; nxt < n; nxt++) if (nxt != v && isEdge(nxt, v) && !used[nxt]) dfs2(nxt);
    }
    void init(){
        memset(who, -1, sizeof(who)); memset(used, 0, sizeof(used));
        for (int i = 0; i < n; i++) if (!used[i]) dfs1(i);
        memset(used, 0, sizeof(used));
        for (int i = 0; i < n; i++){
            int v = order[n-1-i];
            if (!used[v]) dfs2(v), cc++;
        }
    }
} g;

void dfs(int c){
    vis[c]=1; //cout << c << '\n';
    for (int i = 0; i < n; i++) if (!vis[i] && isEdge(c, i)) dfs(i);
}
void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) cin >> a[i];
    ll ans=0; vis.assign(n, 0); g.init();
    for (int i = 0; i < n; i++) if (!vis[i] && sz(g.comp[g.who[i]]) > 1) {
        for (int j = 0; j < n; j++) if (vis[j]) ans -= a[j];
        dfs(i);
        for (int j = 0; j < n; j++) if (vis[j]) ans += a[j];
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}