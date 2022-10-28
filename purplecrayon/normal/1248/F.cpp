#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e6+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

vector<int> g[MAXN], gr[MAXN], order, comp[MAXN];
int cc=0;
bool used[MAXN];
void dfs1 (int v) {
    used[v] = true;
    for (auto nxt : g[v]) if (!used[nxt]) dfs1(nxt);
    order.push_back(v);
}
void dfs2(int v) {
    used[v] = true; comp[cc].push_back(v);
    for (auto nxt : gr[v]) if (!used[nxt]) dfs2(nxt);
}
vector<pair<int, int>> ed;
void add(int a, int b){
    g[a].push_back(b), gr[b].push_back(a);
    ed.push_back({a, b});
}
void init(int n){
    fill(used, used+n, 0);
    for (int i = 0; i < n; i++) if (!used[i]) dfs1(i);
    fill(used, used+n, 0);
    for (int i = 0; i < n; i++){
        int v = order[n-1-i];
        if (!used[v]) dfs2(v), cc++;
    }
}

void solve(){
    int n, m; cin >> n >> m;
    order.clear(); cc=0;
    for (int i = 0; i < n; i++) g[i].clear(), gr[i].clear(), comp[i].clear();
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b, --a, --b; add(a, b);
    }
    init(n);
    if (cc == 1){ cout << "No\n"; return; }
    cout << "Yes\n";  vector<bool> isJudge(n, 1);
    int p=sz(comp[0]), j = n-p;
    cout << j << ' ' << p << '\n'; 
    for (auto it : comp[0]) isJudge[it] = 0;
    for (int i = 0; i < n; i++) if (isJudge[i]) cout << (i+1) << ' '; cout << '\n';
    for (int i = 0; i < n; i++) if (!isJudge[i]) cout << (i+1) << ' ';  cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; 
    while (t--) solve();
}