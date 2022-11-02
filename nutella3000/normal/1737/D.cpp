#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const ll inf = 1e15 + 7;
const int N = 505;

int n, m;
ll d[N][N], dp[N][N];
ll g[N][N];
ll best[N][N][3];
ll dick[N][2 * N];

void clear() {
    for (int i = 0; i < n; ++i) {
        fill(d[i], d[i] + n, inf);
        fill(dp[i], dp[i] + n, inf);
        fill(g[i], g[i] + n, inf);
        for (int j = 0; j < n; ++j)
            fill(best[i][j], best[i][j] + 3, inf);
        fill(dick[i], dick[i] + 2 * n, inf);
    }
}

void build_d() {
    for (int st = 0; st < n; ++st) {
        queue<int> bfs({st});
        d[st][st] = 0;
        while (size(bfs)) {
            int u = bfs.front();
            bfs.pop();
            for (int v = 0; v < n; ++v) {
                if (g[u][v] < inf && d[st][v] > d[st][u] + 1) {
                    d[st][v] = d[st][u] + 1;
                    bfs.push(v);
                }
            }
        }
    }
}

void build_best() {
    for (int u = 0; u < n; ++u) {
        for (int v = 0; v < n; ++v) {
            if (d[u][v] >= inf) continue;
            for (int to = 0; to < n; ++to) {
                chmin(best[u][v][d[to][v] - (d[u][v] - 1)], g[u][to]);
            }
        }
    }
    for (int u = 0; u < n; ++u) {
        for (int v = 0; v < n; ++v) {
            if (d[v][u] >= inf) continue;

            for (int type = 0; type < 3; ++type) {
                ll dist = type + (d[v][u] - 1);
                ll cost = best[v][u][type];
                
                if (cost >= inf) continue;

                ll pre = (min(dist, d[v][u]) + 1) * cost;
                for (int d = 0; d < 2 * n; ++d) {
                    chmin(dick[u][d], pre + (d + 1) * cost);
                    if (dick[u][d] - dick[u][d-1] < cost) {
                        break;
                    }
                }
            }
        }
    }
}

void build_dp() {
    for (int u = 0; u < n; ++u) {
        for (int v = 0; v < n; ++v) {
            for (int mid = 0; mid < n; ++mid) {
                if (d[u][mid] < inf && d[mid][v] < inf) {
                    for (int type = 0; type < 3; ++type) {
                        ll cnt = (d[u][mid] + (d[mid][v] - 1 + type) + 1);
                        if (cnt < inf && best[mid][v][type] < inf) {
                            chmin(dp[u][v], cnt * best[mid][v][type]);
                        }
                    }
                    chmin(dp[u][v], dick[mid][d[u][mid] + d[mid][v]]);
                }
            }
        }
    }
}

void floyd() {
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                chmin(dp[i][j], dp[i][k] + dp[k][j]);
}

void run() {
    cin >> n >> m;
    clear();
    for (int i = 0; i < m; ++i) {
        int u, v; ll w; cin >> u >> v >> w; --u, --v;
        chmin(g[u][v], w);
        chmin(g[v][u], w);
    }
    build_d();
    build_best();
    build_dp();
    floyd();
    cout << dp[0][n-1] << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}