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
const ll INFL = 1e18 + 123;
const double PI = atan2(0, -1);
mt19937 tw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(tw) % (y - x + 1) + x; }

const int MAXN = 255;

int field[MAXN][MAXN];
char buf[MAXN];

pair<pii, int> qu[MAXN * MAXN];
ll res[MAXN][MAXN];
bool used[MAXN][MAXN];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);
    cerr << fixed << setprecision(15);
    cout << fixed << setprecision(15);
    
    int n, m, p, q;
    scanf("%d%d%d%d", &n, &m, &q, &p);

    vector<pair<pii, int>> start;
    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        for (int j = 0; j < m; ++j) {
            if (buf[j] == '*') {
                field[i][j] = 1;
            }
            if ('A' <= buf[j] && buf[j] <= 'Z') {
                start.puba({{i, j}, (buf[j] - 'A' + 1) * q});
            }
        }
    }
    

    for (auto p : start) {
        //cerr << p.ff.ff << " " << p.ff.ss << " " << p.ss << endl;
        int l = 0, r = 0;
        qu[r++] = p;
        used[p.ff.ff][p.ff.ss] = true;
        while (l < r) {
            auto cur = qu[l++];
            int x = cur.ff.ff;
            int y = cur.ff.ss;
            res[x][y] += cur.ss;
            //cerr << "add " << x << " " << y << " " << cur.ss << endl;
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (0 <= nx && nx < n && 0 <= ny && ny < m && !field[nx][ny] && !used[nx][ny]) {
                    if (cur.ss / 2) {
                        qu[r++] = {{nx, ny}, cur.ss / 2};
                        used[nx][ny] = 1;
                    }
                }
            }
        }
        for (int i = 0; i < r; ++i) {
            used[qu[i].ff.ff][qu[i].ff.ss] = 0;
        }
    }
    
    /*
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cerr << field[i][j];
        }
        cerr << endl;
    }*/

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            //cerr << res[i][j] << " ";
            if (res[i][j] > p) {
                ++ans;
            }
        }
        //cerr << endl;
    }

    cout << ans << "\n";
    
    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}