#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 3e5 + 5;

struct edge {
    int u, v, w;
    edge(): u(), v(), w() {}
    edge(int _u, int _v, int _w): u(_u), v(_v), w(_w) {}
};

int n;
edge edges[N];

int dp[N], temp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        edges[i] = edge(u, v, w);
    }

    sort(edges, edges + m + 1, [&] (edge x, edge y) {
        return x.w < y.w;
    });

    vector<int> visited;
    for (int i = 1; i <= m + 1; i++) {
        edge e = edges[i], e1 = edges[i-1];
        if (e.w != e1.w) {
            while (!visited.empty()) {
                dp[visited.back()] = max(dp[visited.back()], temp[visited.back()]);
                temp[visited.back()] = 0;
                visited.pop_back();
            }
        }
        temp[e.v] = max(temp[e.v], 1 + dp[e.u]);
        visited.push_back(e.v);
    }

    cout << *max_element(dp, dp + n + 1) << "\n";
    return 0;
}