#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct fenwick_tree {
    using F = std::function<T(const T&, const T&)>;

    int n;
    std::vector<T> bit;
    F f;

    fenwick_tree() : n(), f() {}
    fenwick_tree(int n, F f = plus<T>()) : n(n), bit(n + 1, 0), f(f) {}

    void add(int i, T val) {
        for (++i; i <= n; i += i & -i) {
            bit[i] = f(bit[i], val);
        }
    }

    T query(int i) {
        T ans = 0;
        for (++i; i; i -= i & -i) {
            ans = f(ans, bit[i]);
        }
        return ans;
    }
};

constexpr int N = 100000 + 1;

int n, a[N], p[N], d[N], timer, tin[N], tout[N];
string name[N];
vector<int> g[N], lvl[N];
vector<tuple<int, int, int>> queries[N];

void dfs(int x) {
    tin[x] = timer++;
    lvl[d[x]].push_back(x);
    for (int i : g[x]) {
        d[i] = 1 + d[x];
        dfs(i);
    }
    tout[x] = timer++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    cin >> n, n += 1;
    for (int i = 1; i < n; i++) {
        cin >> name[i] >> p[i];
        g[p[i]].push_back(i);
    }

    dfs(0);

    int mx_depth = *max_element(d, d + n);

    int q;
    cin >> q;

    vector<int> ans(q);

    for (int i = 0, v, k; i < q; i++) {
        cin >> v >> k;
        int dep = d[v] + k;

        if (dep > mx_depth) continue;

        int l = lower_bound(lvl[dep].begin(), lvl[dep].end(), v, [&](int i, int j) {
            return tin[i] < tin[j];
        }) - lvl[dep].begin();

        swap(tin[v], tout[v]);
        int r = lower_bound(lvl[dep].begin(), lvl[dep].end(), v, [&](int i, int j) {
            return tin[i] < tin[j];
        }) - lvl[dep].begin();
        swap(tin[v], tout[v]);

        if (l < r) {
            queries[dep].emplace_back(l, r - 1, i);
        }
    }

    for (int i = 1; i <= mx_depth; i++) {
        vector<string> names;
        names.reserve(lvl[i].size());
        for (int v : lvl[i]) {
            names.push_back(name[v]);
        }

        sort(names.begin(), names.end());
        names.erase(unique(names.begin(), names.end()), names.end());

        for (int v : lvl[i]) {
            a[v] = lower_bound(names.begin(), names.end(), name[v]) - names.begin();
        }

        fenwick_tree<int> ft(lvl[i].size());
        vector<int> last(names.size(), -1);

        vector<vector<pair<int, int>>> que(lvl[i].size());
        for (auto &[l, r, i] : queries[i]) {
            que[r].emplace_back(l, i);
        }

        for (int r = 0; r < int(lvl[i].size()); r++) {
            int v = lvl[i][r];
            if (last[a[v]] != -1)
                ft.add(last[a[v]], -1);
            ft.add(last[a[v]] = r, 1);
            for (auto &[l, i] : que[r]) {
                ans[i] = ft.query(r) - ft.query(l - 1);
            }
        }
    }

    for (int i = 0; i < q; i++) cout << ans[i] << '\n';
	return 0;
}