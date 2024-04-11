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

int n, sz, c[2];
ll ans;
vector<int> g[N];

bool visited[N], odd;

void firsdfs(int x) {
    visited[x] = true;
    sz++;

    for (int &i : g[x]) {
        if (!visited[i])
            firsdfs(i);
    }
}

set<int> s[2];

void dfs(int x, int d = 0) {
    if (odd)
        return;

    s[d % 2].insert(x);
    ans += c[d % 2];
    c[d % 2] += 1;

    visited[x] = true;

    for (int &i : g[x]) {
        if (s[d % 2].find(i) != s[d % 2].end()) {
            odd = true;
            break;
        }
        if (!visited[i])
            dfs(i, d + 1);
    }

    s[d % 2].erase(x);
}

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

    int best = 0, cnt = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            sz = 0;
            firsdfs(i);

            cnt += (sz == 2);
            best = max(best, sz);
        }
    }

    if (best == 1) {
        cout << 3 << " " << (n * (ll)(n - 1) * (n - 2)) / 6 << "\n";
        return 0;
    }

    if (best == 2) {
        cout << 2 << " " << (n - 2) * (ll)cnt << "\n";
        return 0;
    }

    fill(visited, visited + n + 1, false);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            s[0].clear();
            s[1].clear();

            c[0] = c[1] = 0;
            dfs(i);
        }
    }

    if (odd) {
        cout << "0 1\n";
        return 0;
    }

    cout << 1 << " " << ans << "\n";
    return 0;
}