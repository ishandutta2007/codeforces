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

int n, m, p, q;
vector<pair<int, int>> edges, g[N];
ll sum;

bool visited[N];

void dfs(int x) {
    visited[x] = true;
    for (auto &[v, w] : g[x]) {
        if (!visited[v]) {
            dfs(v);
        }
        sum += w;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> p >> q;
    for (int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
        edges.emplace_back(u, v);
    }

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            sum = 0;
            dfs(i);
            pq.emplace(sum / 2, i);
        }
    }

    vector<pair<int, int>> ans;
    while (pq.size() > q) {
        int x1, x2;
        ll v1, v2;

        x1 = pq.top().second; v1 = pq.top().first; pq.pop();
        x2 = pq.top().second; v2 = pq.top().first; pq.pop();

        ans.emplace_back(x1, x2);
        pq.emplace(v1 + v2 + min((ll)1e9, v1 + v2 + 1), x1);
    }

    if (pq.size() != q or p - (int)ans.size() < 0 or (p and ans.empty() and edges.empty())) {
        cout << "NO\n";
        return 0;
    }

    p -= ans.size();

    if (ans.empty()) {
        for (int i = 0; i < p; i++)
            ans.push_back(edges.front());
    }
    else {
        for (int i = 0; i < p; i++)
            ans.push_back(ans.front());
    }

    cout << "YES\n";
    for (auto &[u, v] : ans) cout << u << " " << v << "\n";
    return 0;
}