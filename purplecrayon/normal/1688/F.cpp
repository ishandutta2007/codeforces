#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;

void solve() {
    int n, m; cin >> n >> m;
    vector<ll> a(n);
    for (auto& x : a) {
        int c; cin >> c;
        x += c;
    }
    for (auto& x : a) {
        int c; cin >> c;
        x -= c;
    }
    for (int i = 1; i < n; i++) a[i] += a[i-1];
    a.insert(a.begin(), 0LL);

    set<int> s;
    for (int i = 1; i <= n; i++) if (a[i] != 0) s.insert(i);


    queue<int> q;

    vector<pair<int, int>> b(m);
    vector<vector<int>> use(n + 1);
    vector<bool> vis(m);

    auto can = [&](int i) {
        if (!vis[i] && a[b[i].first] == 0 && a[b[i].second] == 0) return true;
        return false;
    };

    for (int i = 0; i < m; i++) {
        cin >> b[i].first >> b[i].second, --b[i].first;
        // a[l] == a[r] == 0
        if (can(i)) {
            vis[i] = 1;
            q.push(i);
        }
        use[b[i].first].push_back(i);
        use[b[i].second].push_back(i);
    }
    while (sz(q)) {
        int c = q.front(); q.pop();
        auto [l, r] = b[c];
        auto it = s.lower_bound(l);
        while (it != s.end() && *it <= r) {
            int x = *it;
            a[x] = 0;
            s.erase(it);
            for (int i : use[x]) if (can(i)) {
                vis[i] = 1;
                q.push(i);
            }
            it = s.lower_bound(l);
        }
    }
    cout << (sz(s) ? "NO\n" : "YES\n");
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}