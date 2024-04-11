#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <queue>
#include <cassert>
#include <bitset>
#include <string>
#include <numeric>
#pragma GCC optimize("O3")

using namespace std;

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 1e9 + 7, N = 4e2 + 2;

struct Fenwick {
    int n;
    vector <int> t;
    Fenwick(int m = 0) {
        n = m;
        t.resize(n);
    }
    void add(int i, int x) {
        for (; i < n; i |= i + 1)
            t[i] += x;
    }
    int get(int i) {
        int res = 0;
        for (; i >= 0; i &= i + 1, --i)
            res += t[i];
        return res;
    }
    int getKth(int k) {
        if (get(n - 1) < k) return -1;
        int cur = 0;
        for (int i = 18; i >= 0; --i) {
            if (cur + (1 << i) >= n) continue;
            if (t[cur + (1 << i) - 1] >= k) continue;
            k -= t[cur + (1 << i) - 1];
            cur += (1 << i);
        }
        return cur;
    }
} tree;

struct query {
    int l, k, id;
    query(int l = 0, int k = 0, int id = 0) :
        l(l), k(k), id(id) {}
};
vector <vector <int>> g;
vector <int> a, ans, cur;
vector <vector <query>> qs;

vector <set <int>> freq;

void dfs(int v) {
    freq[cur[a[v]]].erase(a[v]);
    if (cur[a[v]]) tree.add(cur[a[v]], -1);
    cur[a[v]]++;
    freq[cur[a[v]]].insert(a[v]);
    tree.add(cur[a[v]], 1);
    for (auto& x : qs[v]) {
        int get = tree.getKth(x.k + tree.get(x.l - 1));
        if (get == -1) {
            ans[x.id] = -1;
        }
        else {
            ans[x.id] = *(freq[get].begin()) + 1;
        }
    }
    for (auto u : g[v]) {
        dfs(u);
    }
    freq[cur[a[v]]].erase(a[v]);
    tree.add(cur[a[v]], -1);
    cur[a[v]]--;
    freq[cur[a[v]]].insert(a[v]);
    if (cur[a[v]]) tree.add(cur[a[v]], 1);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(12);
    int tt; cin >> tt;
    while (tt--) {
        int n, q; cin >> n >> q;
        a.assign(n, 0);
        g.assign(n, {});
        freq.assign(n + 1, {});
        cur.assign(n, 0);
        qs.assign(n, {});
        for (auto& x : a) cin >> x, --x;
        for (int i = 1, p; i < n; ++i) {
            cin >> p; --p;
            g[p].push_back(i);
        }
        ans.assign(q, 0);
        for (int i = 0; i < q; ++i) {
            int v, l, k; cin >> v >> l >> k;
            qs[v - 1].push_back(query(l, k, i));
        }
        tree = Fenwick(n + 1);
        dfs(0);
        for (auto& x : ans) cout << x << ' ';
        cout << '\n';
    }
}