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
const int N = 1e5 + 5;

int n, k, p[N], d[N], found1, found2;
vector<int> g[N];

set<int> active;
bool visited[N];

void dfs(int x = 1, int pa = 0, int dep = 0) {
    if (found1)
        return;

    visited[x] = true;
    d[x] = dep;

    p[x] = pa;
    active.insert(x);

    for (int &i : g[x]) {
        if (active.find(i) != active.end() and dep - d[i] >= k) {
            found1 = x;
            found2 = i;
            break;
        }
        if (!visited[i])
            dfs(i, x, dep + 1);
    }

    active.erase(x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int m;
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs();
    vector<int> ans;

    while (found1 != found2) {
        ans.push_back(found1);
        found1 = p[found1];
    }

    ans.push_back(found2);

    cout << ans.size() << "\n";
    for (int i : ans) cout << i << " ";
    return 0;
}