#include "bits/stdc++.h"
using namespace std;

template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 17, MAXA = 1e6+10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const int INF = 1e9+10;

vector<int> adj[MAXN], v;
bool vis[MAXN];

void dfs(int c=0) {
    vis[c] = 1;
    v.push_back(c);
    for (auto nxt : adj[c]) if (!vis[nxt])  {
        dfs(nxt);
        v.push_back(c);
    }
}
void solve(){
    int n, m, k; cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }
    memset(vis, 0, sizeof(vis));
    dfs();

    int tot = 0;
    int size = (sz(v)+k-1)/k;
    for (int i = 0; i < sz(v); i+=size) {
        cout << min(sz(v), i+size)-i << ' ';
        for (int j = i; j < min(sz(v), i+size); j++) cout << v[j]+1 << ' ';
        cout << '\n';
        tot++;
    }
    while ((tot++) < k) cout << "1 1\n";
} 
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}