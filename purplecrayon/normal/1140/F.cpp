#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 6e5+10, MOD = 1e9+7;
const int Q = 3e5+10;
const int M = 3e5+10;

int p[4 * N], sz[4 * N];
pair<int, int> cnt[4 * N];
ll ans = 0;

int find_set(int v) {
    return v == p[v] ? v : find_set(p[v]);
}

int q;
map<pair<int, int>, int> range;
vector<pair<int, int>> t[4 * Q];

void add_range(int v, int tl, int tr, int l, int r, pair<int, int> e) {
    if (r < tl || l > tr) return;
    if (l <= tl && tr <= r) {
        t[v].push_back(e);
        return;
    }
    int tm = (tl + tr) / 2;

    add_range(2*v, tl, tm, l, r, e), add_range(2*v+1, tm+1, tr, l, r, e);
}
void rec(int v, int tl, int tr) {
    auto get_cnt = [&](int x) {
        return (long long) cnt[x].first * cnt[x].second;
    };

    for (auto& [x, y] : t[v]) {
        x = find_set(x), y = find_set(y);
        if (x == y) continue;
        if (sz[x] < sz[y]) swap(x, y);

        ans -= get_cnt(x) + get_cnt(y);
        cnt[x].first += cnt[y].first, cnt[x].second += cnt[y].second;
        ans += get_cnt(x);

        p[y] = x, sz[x] += sz[y];
    }

    if (tl == tr) {
        cout << ans << ' ';
    } else {
        int tm = (tl + tr) / 2;
        rec(2*v, tl, tm), rec(2*v+1, tm+1, tr);
    }

    reverse(t[v].begin(), t[v].end());
    for (auto& [x, y] : t[v]) {
        if (x == y) continue;
        p[y] = y, sz[x] -= sz[y];

        ans -= get_cnt(x);
        cnt[x].first -= cnt[y].first, cnt[x].second -= cnt[y].second;
        ans += get_cnt(x) + get_cnt(y);
    }
}
void solve() {
    cin >> q;
    for (int t = 0; t < q; t++) {
        int x, y; cin >> x >> y, --x, --y; y += M;
        if (range.count({x, y})) {
            add_range(1, 0, q-1, range[{x, y}], t-1, {x, y});
            range.erase({x, y});
        } else {
            range[{x, y}] = t;
        }
    }
    for (auto [k, t] : range) {
        add_range(1, 0, q-1, t, q-1, k);
    }
    for (int i = 0; i < N; i++) {
        p[i] = i, sz[i] = 1;
        if (i < M) cnt[i] = {1, 0};
        else cnt[i] = {0, 1};
    }
    rec(1, 0, q-1);
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}