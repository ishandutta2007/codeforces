#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define MP make_pair
#define L first
#define R second
#define PB push_back
#define PF push_back

const int maxn = 1000 + 10;
string s[maxn];
vector<pii> adj[2 * maxn * maxn];
int dis[2 * maxn * maxn];
bool mark[2 * maxn * maxn];
int n, m;

// i x y -> i * n * m + x * m + y
// 1 2 2 -> 1 * 3 * 4 + 2 * 4 + 2 = 12 + 8 + 2 = 22

int conv(int i, int x, int y) {
    return i * n * m + x * m + y;
}

pair<int, pii> vnoc(int idx) {
    int i = idx / (n * m);
    idx %= n * m;
    int x = idx / m;
    idx %= m;
    int y = idx;
    return MP(i, MP(x, y));
}

void add_edge(int u, int v, int w) {
    adj[u].PB(MP(v, w));
    adj[v].PB(MP(u, w));
}

int bfs(int s, int t) {
    deque<int> q;
    memset(dis, 63, sizeof dis);
    dis[s] = 0;
    q.PB(0);
    while (q.size()) {
        int u = q.front();
        q.pop_front();
        if (mark[u])
            continue;
        mark[u] = true;
        for (pii e: adj[u]) {
            int v = e.L,
                w = e.R;
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                if (w == 1)
                    q.PB(v);
                else
                    q.PF(v);
            }
        }
    }
    return dis[t];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j + 1 < m; j++)
            add_edge(conv(0, i, j), conv(0, i, j + 1), 0);
    for (int i = 0; i + 1 < n; i++)
        for (int j = 0; j < m; j++)
            add_edge(conv(1, i, j), conv(1, i + 1, j), 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] == '#')
                add_edge(conv(0, i, j), conv(1, i, j), 1);
    int ans = bfs(conv(0, 0, 0), conv(0, n - 1, m - 1));
    if (ans < n * m)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}