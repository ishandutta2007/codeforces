#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const ll inf = 1e15 + 5;
const int N = 3e5 + 5;

struct edge {
    int v, w, idx;
    edge() : v(), w(), idx() {}
    edge(int u, int w, int i) {
        this->v = u;
        this->w = w;
        this->idx = i;
    }
};

int n, m, weight[N];
vector<edge> g[N];

pair<ll, int> d[N];
bool visited[N];

vector<int> ans;

void dijkstra(int s = 1) {
    fill(visited, visited + n + 1, false);
    for (int i = 1; i <= n; i++) d[i] = {inf, -1};

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> q;
    q.push({0, s});

    d[s] = {0, -1};
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();

        if (visited[u])
            continue;

        if (d[u].second != -1)
            ans.push_back(d[u].second);
        visited[u] = true;

        for (const edge &i : g[u]) {
            if (d[i.v].first > d[u].first + i.w) {
                d[i.v].first = d[u].first + i.w;
                d[i.v].second = i.idx;
                q.push({d[i.v].first, i.v});
            }
            else if (d[i.v].first == d[u].first + i.w) {
                if (i.w < weight[d[i.v].second])
                    d[i.v].second = i.idx;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].emplace_back(v, w, i);
        g[v].emplace_back(u, w, i);
        weight[i] = w;
    }

    int s;
    cin >> s;

    dijkstra(s);

    ll sum = 0;
    for (int i : ans) sum += weight[i];

    cout << sum << "\n";
    for (int i : ans) cout << i + 1 << " ";
    return 0;
}