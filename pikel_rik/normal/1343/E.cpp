#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 1e9 + 5;

void bfs(vvi &g, int s, vector<int> &lvl) {
    queue<int> q;
    q.push(s);

    vi visited(g.size());
    visited[s] = 1;
    lvl[s] = 0;

    while (!q.empty()) {
        int a = q.front();
        q.pop();

        for (int &i : g[a]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = 1;
                lvl[i] = lvl[a] + 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int n, m, a, b, c;
        cin >> n >> m >> a >> b >> c;

        vi p(m);
        for (int i = 0; i < m; i++) cin >> p[i];

        vvi g(n + 1);

        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            g[v].push_back(u);
            g[u].push_back(v);
        }

        vvi lvl(4, vi(n + 1));
        bfs(g, a, lvl[1]);
        bfs(g, b, lvl[2]);
        bfs(g, c, lvl[3]);

        sort(all(p));
        vector<ll> prefix(m + 1);
        prefix[0] = 0;

        for (int i = 1; i <= m; i++)
            prefix[i] = prefix[i-1] + p[i-1];

        ll min_cost = LLONG_MAX;
        for (int i = 1; i <= n; i++) {
            if (lvl[1][i] + lvl[2][i] + lvl[3][i] <= m)
                min_cost = min(min_cost, prefix[lvl[2][i]] + prefix[lvl[1][i] + lvl[2][i] + lvl[3][i]]);
        }

        cout << min_cost << "\n";
    }

    return 0;
}