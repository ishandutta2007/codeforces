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
const int MAXN = 85;

int graph[MAXN][MAXN];
ll d[2][MAXN][MAXN][MAXN];

ll rec(int l, int r, int flag, int k) {
    if (k == 0) {
        return 0;
    }
    if (l + 1 == r) {
        return INF;
    }
    if (d[flag][l][r][k] != -1) {
        return d[flag][l][r][k];
    }

    ll res = INF;
    int from = flag ? r : l;
    for (int to = l + 1; to < r; ++to) {
        res = min(res, min(rec(l, to, 1, k - 1) + graph[from][to], rec(to, r, 0, k - 1) + graph[from][to]));
    }
    //cerr << flag << " " << l << " " << r << " " << k << " " << res << endl;
    return d[flag][l][r][k] = res;
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    int n, k;
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n + 2; ++i) {
        for (int j = 0; j < n + 2; ++j) {
            graph[i][j] = INF;
        }
    }

    for (int i = 1; i < n + 1; ++i) {
        graph[0][i] = 0;
    }

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        graph[a][b] = min(graph[a][b], c);
    }

    memset(d, -1, sizeof d);

    ll tmp = rec(0, n + 1, 0, k);
    if (tmp >= INF) {
        cout << "-1\n";
    } else {
        cout << tmp << "\n";
    }

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}