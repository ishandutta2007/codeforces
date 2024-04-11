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

int n;
vector<pair<int, int>> g[N];
vector<int> train[N];

ll d[N];
bool visited[N];

void Dijkstra(int s = 1) {
    fill(visited, visited + n + 1, false);
    for (int i = 1; i <= n; i++) d[i] = LLONG_MAX;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> q;
    q.push({0, s});

    d[s] = 0;
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();

        if (visited[u])
            continue;
        visited[u] = true;

        for (pair<int, int> &i : g[u]) {
            if (i.second > 0) {
                if (d[i.first] > d[u] + i.second) {
                    d[i.first] = d[u] + i.second;
                    q.push({d[i.first], i.first});
                }
            }
            else {
                if (d[i.first] > d[u] - i.second) {
                    d[i.first] = d[u] - i.second;
                    q.push({d[i.first], i.first});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    for (int i = 0; i < k; i++) {
        int u, w;
        cin >> u >> w;
        g[1].emplace_back(u, -w);
        g[u].emplace_back(1, -w);
        train[u].push_back(w);
    }

    Dijkstra();

    int c = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        bool flag = false;

        for (int x : train[i]) {
            if (d[i] < x)
                c++;
            else if (d[i] == x) {
                cnt++;
                if (cnt > 1)
                    continue;
                for (auto &[v, w]: g[i]) {
                    if (w > 0 and d[v] + w == d[i]) {
                        flag = true;
                        break;
                    }
                }
            }
        }
        if (!flag)
            c += max(0, cnt - 1);
        else c += cnt;
    }

    cout << c << "\n";
    return 0;
}