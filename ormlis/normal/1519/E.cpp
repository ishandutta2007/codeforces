#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

// using namespace __gnu_pbds;
/*
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
*/

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int INFi = 2e9 + 5;
const int maxN = 6e5 + 100;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

vector<pair<int, int>> g[maxN];
bool was[maxN];
bool used[maxN];

vector<pair<int, int>> answer;

bool dfs(int v, int p = -1) {
    was[v] = true;
    vector<int> edges;
    for(auto &[u, i] : g[v]) {
        if (used[i]) continue;
        if (i == p) continue;
        if (was[u]) {
            edges.push_back(i);
            continue;
        }
        if (dfs(u, i)) {
            edges.push_back(i);
        }
    }
    while(edges.size() >= 2) {
        int a = edges.back();
        edges.pop_back();
        int b = edges.back();
        edges.pop_back();
        answer.emplace_back(a, b);
        used[a] = true;
        used[b] = true;
    }
    if (!edges.empty() && p != -1) {
        answer.emplace_back(p, edges.back());
        used[edges.back()] = true;
        used[p] = true;
        return false;
    }
    return true;
}

void solve() {
    int n; cin >> n;
    vector<ar<int, 4>> arr(n);
    range(i, n) range(j, 4) cin >> arr[i][j];
    map<pair<ll, ll>, int> mp;
    int cur = 1;
    range(i, n) {
        // (c/d + 1)/(a/b) == (cb + db) / (ad)
        auto [a, b, c, d] = arr[i];
        pair<ll, ll> kek = {1ll * c * b + 1ll * d * b, 1ll * a * d};
        ll gg = __gcd(kek.first, kek.second);
        kek.first /= gg;
        kek.second /= gg;
        if (!mp.count(kek)) {
            mp[kek] = cur++;
        }
        int u = mp[kek];
        // (c/d)/(a/b + 1) == (cb) / (ad + db)
        kek = {1ll * c * b, 1ll * a * d + 1ll * d * b};
        gg = __gcd(kek.first, kek.second);
        kek.first /= gg;
        kek.second /= gg;
        if (!mp.count(kek)) {
            mp[kek] = cur++;
        }
        int v = mp[kek];
        g[u].emplace_back(v, i);
        g[v].emplace_back(u, i);
    }
    for(int i = 1; i < cur; ++i) {
        if (was[i]) continue;
        dfs(i);
    }
    cout << answer.size() << '\n';
    for(auto &[a, b] : answer) cout << a + 1 << ' ' << b + 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}