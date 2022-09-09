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

char field[MAXN][MAXN];

int dist[4][MAXN][MAXN];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m;

bool on_field(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m && field[x][y] != '*';
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d%d", &n, &m);

    int sx = -1, sy = -1, fx = -1, fy = -1;
    for (int i = 0; i < n; ++i) {
        scanf("%s", field[i]);
        for (int j = 0; j < m; ++j) {
            if (field[i][j] == 'S') {
                sx = i;
                sy = j;
                field[i][j] = '.';
            }
            if (field[i][j] == 'T') {
                fx = i;
                fy = j;
                field[i][j] = '.';
            }
        }
    }
    
    memset(dist, 127, sizeof dist);

    priority_queue<pair<int, tuple<int, int, int>>> q;

    for (int d = 0; d < 4; ++d) {
        q.push({0, {d, sx, sy}});
    }

    while (szof(q)) {
        int d;
        int dir, x, y;
        do {
            d = -q.top().ff;
            tie(dir, x, y) = q.top().ss;
            q.pop();
        } while (szof(q) && dist[dir][x][y] <= d);

        if (dist[dir][x][y] <= d) {
            break;
        }

        dist[dir][x][y] = d;

        if (on_field(x + dx[dir], y + dy[dir])) {
            q.push({-d, {dir, x + dx[dir], y + dy[dir]}});
        }

        for (int i = -1; i <= 1; i += 2) {
            q.push({-d - 1, {(dir + i + 4) % 4, x, y}});
        }
    }   

    int res = INF;
    for (int i = 0; i < 4; ++i) {
        res = min(res, dist[i][fx][fy]);
    }

    cerr << res << "\n";

    if (res <= 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}