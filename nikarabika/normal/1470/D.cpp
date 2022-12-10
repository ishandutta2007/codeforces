//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

int solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    while (q--)
        solve();
    return 0;
}

const int maxn = 300 * 1001;
bool mark[maxn],
     choose[maxn];
vector<int> adj[maxn];
int seen;

void dfs(int u) {
    if (mark[u]) return;
    seen++;
    mark[u] = true;
    if (choose[u])
        for (int v: adj[u])
            choose[v] = false;
    for (int v: adj[u])
        dfs(v);
}

int solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        adj[i].clear();
        choose[i] = true;
        mark[i] = false;
    }
    for (int i = 0; i < m; i++) {
        int fi, se;
        cin >> fi >> se;
        fi--, se--;
        adj[fi].PB(se);
        adj[se].PB(fi);
    }
    seen = 0;
    dfs(0);
    if (seen != n)
        return cout << "NO\n", 0;
    cout << "YES\n";
    vector<int> ans;
    for (int u = 0; u < n; u++)
        if (choose[u])
            ans.PB(u);
    cout << sz(ans) << '\n';
    for (auto u: ans)
        cout << u + 1 << ' ';
    cout << '\n';
    return 0;
}