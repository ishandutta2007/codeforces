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
//const int INF = 1e9 + 7;
const double PI = atan2(0, -1);
const int MAXN = 1e5 + 5;
const ll INF = 1e18;

int n, m, k;
ll type[4][MAXN * 2];
int dx[4] = {1, 1, -1, -1};
int dy[4] = {1, -1, -1, 1};

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d%d%d", &n, &m, &k);

    vector<pii> inp;
    for (int i = 0; i < k; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);

        inp.puba({x, y});
    }

    int nx = 0, ny = 0;
    int d = 0;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < MAXN * 2; ++j) {
            type[i][j] = INF;
        }
    }
    ll nt = 0;

    while (true) {
        if (d == 0 || d == 2) {
            if (type[d][nx - ny + MAXN] < INF) {
                break;
            }
            type[d][nx - ny + MAXN] = min(type[d][nx - ny + MAXN], nt);
            if (d == 0) {
                int tmp = min(n - nx, m - ny);
                nx += tmp;
                ny += tmp;
                nt += tmp;
                if (nx == n) {
                    d = 3;
                } else {
                    d = 1;
                }
            } else {
                int tmp = min(nx, ny);
                nx -= tmp;
                ny -= tmp;
                nt += tmp;
                if (nx == 0) {
                    d = 1;
                } else {
                    d = 3;
                }
            }
        } else {
            if (type[d][nx + ny] < INF) {
                break;
            }
            type[d][nx + ny] = min(type[d][nx + ny], nt);
            if (d == 1) {
                int tmp = min(n - nx, ny);
                nx += tmp;
                ny -= tmp;
                nt += tmp;
                if (nx == n) {
                    d = 2;
                } else {
                    d = 0;
                }
            } else {
                int tmp = min(nx, m - ny);
                nx -= tmp;
                ny += tmp;
                nt += tmp;
                if (nx == 0) {
                    d = 0;
                } else {
                    d = 2;
                }
            }
        }
        if ((nx == 0 && ny == 0) || (nx == 0 && ny == m) || (nx == n && ny == 0) || (nx == n && ny == m)) {
            break;
        }
    }

    for (int i = 0; i < k; ++i) {
        ll ans = INF;
        if (type[0][inp[i].ff - inp[i].ss + MAXN] < INF) {
            ans = min(ans, type[0][inp[i].ff - inp[i].ss + MAXN] + min(inp[i].ff, inp[i].ss));
        }
        if (type[2][inp[i].ff - inp[i].ss + MAXN] < INF) {
            ans = min(ans, type[2][inp[i].ff - inp[i].ss + MAXN] + min(n - inp[i].ff, m - inp[i].ss));
        }

        if (type[1][inp[i].ff + inp[i].ss] < INF) {
            ans = min(ans, type[1][inp[i].ff + inp[i].ss] + min(inp[i].ff, m - inp[i].ss));
        }
        if (type[3][inp[i].ff + inp[i].ss] < INF) {
            ans = min(ans, type[3][inp[i].ff + inp[i].ss] + min(n - inp[i].ff, inp[i].ss));
        }
        if (ans == INF) {
            cout << "-1\n";
        } else {
            cout << ans << "\n";
        }
    }

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}