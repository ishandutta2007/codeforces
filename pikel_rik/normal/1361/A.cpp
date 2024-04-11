#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 5e5 + 5;

int n, t[N], visited[N];
vector<int> g[N], ans;

bool v[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
    for (int i = 1; i <= n; i++) {
        q.push({t[i], i});
    }

    while (!q.empty()) {
        int topic = q.top().first, u = q.top().second;
        q.pop();

        if (topic > g[u].size() + 1) {
            cout << "-1\n";
            return 0;
        }

        fill(v, v + topic + 1, false);

        for (int &i : g[u]) {
            if (visited[i] <= topic)
                v[visited[i]] = true;
        }

        bool flag = true;
        for (int i = 1; i < topic && flag; i++) {
            flag &= v[i];
        }

        flag &= (!v[topic]);

        if (flag) {
            ans.push_back(u);
            visited[u] = topic;
        }
        else {
            cout << "-1\n";
            return 0;
        }
    }

    for (int i : ans) cout << i << " ";
    return 0;
}