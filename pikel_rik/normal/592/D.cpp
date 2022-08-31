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
const int N = 123456 + 5;

int n, m, cnt[N], v, lvl[N];
vector<int> g[N];

bool marked[N], ok[N], visited[N];

void dfs1(int x, int p = 0, bool f = false) {
    cnt[x] = marked[x];
    int c = 0;
    f |= marked[x];

    for (int &i : g[x]) {
        if (i == p) continue;
        dfs1(i, x, f);
        if (!cnt[i]) continue;
        c++;
        cnt[x] += cnt[i];
    }

    if (!cnt[x])
        ok[x] = false;
    else if (c == 1 and cnt[x] == m and !f)
        ok[x] = false;
    else v = x;
}

void bfs(int s) {
    fill(visited, visited + n + 1, false);

    queue<int> q;
    q.push(s);

    lvl[s] = 0;
    visited[s] = true;
    v = s;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int &i : g[x]) {
            if (!visited[i] and ok[i]) {
                q.push(i);
                lvl[i] = lvl[x] + 1;
                visited[i] = true;
                if (lvl[i] > lvl[v])
                    v = i;
                else if (lvl[i] == lvl[v] and i < v)
                    v = i;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        marked[x] = true;
    }

    fill(ok, ok + n + 1, true);
    dfs1(1);

    bfs(v);
    int ans = v;
    bfs(v);
    ans = min(ans, v);

    int sum = 0;
    for (int i = 1; i <= n; i++)
        sum += ok[i];

    cout << ans << "\n" << 2 * sum - 2 - lvl[v] << "\n";
    return 0;
}