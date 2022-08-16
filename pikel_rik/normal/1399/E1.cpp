#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5 + 5;

struct comp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return (a.first - a.first / 2) * (ll)a.second < (b.first - b.first / 2) * (ll)b.second;
    }
};

int n, sz[N];
ll s, cur;
vector<pair<int, int>> g[N];

priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;

void dfs(int x, int p) {
    sz[x] = (p and g[x].size() <= 1);

    for (auto &[i, w] : g[x]) {
        if (i == p) continue;
        dfs(i, x);
        pq.emplace(w, sz[i]);
        cur += w * (ll)sz[i];
        sz[x] += sz[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n >> s;
        for (int i = 1; i <= n; i++) g[i].clear();

        for (int i = 1, u, v, w; i < n; i++) {
            cin >> u >> v >> w;
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }

        cur = 0;
        dfs(1, 0);
        int ans = 0;

        while (cur > s) {
            ans++;

            int w, siz;
            tie(w, siz) = pq.top(); pq.pop();

            cur -= w * (ll)siz;
            w /= 2;
            cur += w * (ll)siz;
            pq.emplace(w, siz);
        }

        while (!pq.empty())
            pq.pop();
        cout << ans << "\n";
    }
    return 0;
}