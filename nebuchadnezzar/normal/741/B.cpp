#include "bits/stdc++.h"
#define puba push_back
#define ff first
#define ss second
#define bend(_x) begin(_x), end(_x)
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const double PI = atan2(0, -1);
const int MAXN = 1005;

int arrw[MAXN], arrb[MAXN], d[MAXN][MAXN];

bool used[MAXN];
vector<int> now;
vector<int> graph[MAXN];

int dfs(int v) {
    used[v] = true;
    now.puba(v);
    for (int to : graph[v]) {
        if (!used[to]) {
            dfs(to);
        }
    }
    return 0;
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    int n, m, w;
    scanf("%d%d%d", &n, &m, &w);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &arrw[i]);
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d", &arrb[i]);
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a; --b;
        graph[a].puba(b);
        graph[b].puba(a);
    }

    memset(d, -1, sizeof d);
    d[0][0] = 0;

    int c = 0;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            now.clear();
            dfs(i);

            int sumw = 0, sumb = 0;
            for (int v : now) {
                sumw += arrw[v];
                sumb += arrb[v];
                for (int j = 0; j < MAXN; ++j) {
                    if (j + arrw[v] < MAXN && d[c + 1][j + arrw[v]] < d[c][j] + arrb[v]) {
                        d[c + 1][j + arrw[v]] = d[c][j] + arrb[v];
                    }
                }
            }

            for (int j = 0; j < MAXN; ++j) {
                if (j + sumw < MAXN && d[c + 1][j + sumw] < d[c][j] + sumb) {
                    d[c + 1][j + sumw] = d[c][j] + sumb;
                }
                d[c + 1][j] = max(d[c + 1][j], d[c][j]);
            }

            ++c;
        }
    }

    int ans = 0;
    for (int i = 0; i <= w; ++i) {
        ans = max(ans, d[c][i]);
    }

    cout << ans << "\n";

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}