#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;

int n, m, p[N];
ll x, a[N];
vector<ar<int, 2>> adj[N];

int find_set(int v) {
    return v == p[v] ? v : p[v] = find_set(p[v]);
}
bool union_sets(int u, int v) {
    if ((u = find_set(u)) == (v = find_set(v))) return false;
    if (a[v] + a[u] < x) return false;
    a[v] += a[u] - x, a[u] = 0;
    assert(a[v] >= 0);
    p[u] = v;
    return true;
}
void solve() {
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back({b, i}), adj[b].push_back({a, i});
    }
    std::iota(p, p + n, 0);

    vector<int> ans; ans.reserve(n);
    for (int i = 0; i < n; i++) if (a[find_set(i)] >= x) {
        vector<int> use{i};
        for (int rep = 0; rep < sz(use) && a[find_set(i)] >= x; rep++) {
            int c = use[rep];
            for (auto [nxt, k] : adj[c]) {
                if (union_sets(c, nxt)) {
                    ans.push_back(k);
                    use.push_back(nxt);
                }
            }
        }
    }
    for (int a = 0; a < n; a++) {
        for (auto [b, k] : adj[a]) if (union_sets(a, b)) {
            ans.push_back(k);
        }
    }
    if (sz(ans) != n-1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int x : ans) cout << x+1 << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}