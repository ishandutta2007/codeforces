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

struct edge {
    int u, f, i;
    edge(int u, int f, int i) : u(u), f(f), i(i) {}
};

int n, lvl[N], dp[N];
vector<edge> g[N];
vector<int> d[N];
vector<edge> edges;

bool visited[N];
void bfs(int s) {
    queue<int> q;
    q.push(s);

    visited[s] = true;
    lvl[s] = 0;
    d[0] = {s};

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (auto &[y, z, i] : g[x]) {
            if (!visited[y]) {
                q.push(y);
                visited[y] = true;
                lvl[y] = lvl[x] + 1;
                d[lvl[y]].push_back(y);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> n >> m;

    for (int i = 0, u, v, w; i < m; i++) {
        cin >> u >> v >> w;
        g[u].emplace_back(v, w, i);
        g[v].emplace_back(u, w, i);
        edges.emplace_back(u, v, w);
    }

    bfs(1);
    for (int de = 1; de <= lvl[n]; de++) {
        for (int x : d[de]) {
            dp[x] = INT_MAX;
            for (auto &[y, z, i] : g[x]) {
                if (lvl[y] == lvl[x] - 1) {
                    if (z)
                        dp[x] = min(dp[x], dp[y]);
                    else dp[x] = min(dp[x], dp[y] + 1);
                }
            }
        }
    }

    int v = n;
    set<int> s;
    vector<int> ans;

    while (v != 1) {
        for (auto &[y, z, i] : g[v]) {
            if (lvl[y] == lvl[v] - 1) {
                if (z and dp[y] == dp[v]) {
                    s.insert(i);
                    v = y;
                    break;
                }
                else if (!z and dp[v] == dp[y] + 1) {
                    ans.push_back(i);
                    s.insert(i);
                    v = y;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < m; i++) {
        if (s.find(i) == s.end() and edges[i].i) {
            ans.push_back(i);
        }
    }

    cout << ans.size() << "\n";
    for (int i : ans) {
        cout << edges[i].u << " " << edges[i].f << " " << 1 - edges[i].i << "\n";
    }
    return 0;
}