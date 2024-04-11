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
const int N = 100;

int n, m, d[N];
vector<pair<int, int>> edges;
vector<int> g[N];
char ans[N];

bool intersect(pair<int, int> a, pair<int, int> b) {
    if (b.first > a.first and b.first < a.second and b.second > a.second)
        return true;
    return b.second > a.first and b.second < a.second and b.first < a.first;
}

bool visited[N], cycle;

void dfs(int x, int dep = 0) {
    visited[x] = true;
    d[x] = dep;

    for (int &i : g[x]) {
        if (!visited[i])
            dfs(i, dep + 1);
        else if ((d[x] - d[i]) % 2 == 0)
            cycle = true;
    }
}

void make(int x, int val) {
    if (val == 1)
        ans[x] = 'o';
    else ans[x] = 'i';
    visited[x] = true;

    for (int &i : g[x]) {
        if (!visited[i])
            make(i, 1 - val);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        if (u > v) swap(u, v);
        edges.emplace_back(u, v);
    }

    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (intersect(edges[i], edges[j])) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    for (int i = 0; i < m; i++) {
        if (!visited[i])
            dfs(i);
    }

    if (cycle) {
        cout << "Impossible\n";
        return 0;
    }

    memset(visited, false, sizeof(visited));
    for (int i = 0; i < m; i++) {
        if (!visited[i])
            make(i, 0);
    }

    for (int i = 0; i < m; i++) cout << ans[i]; cout << "\n";
    return 0;
}