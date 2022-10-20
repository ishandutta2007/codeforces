#include <bits/stdc++.h>

using namespace std;

const int INF = 1e8;
const int N = 2010;
typedef pair<int, int> pi;
const int X[] = {0, 1, 0, -1};
const int Y[] = {1, 0, -1, 0};

int n, m;
int r, c;
int x, y;
char a[N][N];
pi dp[N][N];
int used[N][N];

bool inside(int u, int v) {
    return (u > 0 && u <= n && v > 0 && v <= m);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    scanf("%d %d", &n, &m);
    scanf("%d %d", &r, &c);
    scanf("%d %d", &x, &y);
    for (int i = 1; i <= n; i++) {
        scanf("%s", a[i] + 1);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = pi(INF, INF);
        }
    }
    dp[r][c] = pi(0, 0);
    deque<pi> q;
    used[r][c] = 1;
    q.push_back(pi(r, c));
    while (!q.empty()) {
        pi u = q.front();
        q.pop_front();
        for (int dir = 0; dir < 4; dir++) {
            int newX = u.first + X[dir];
            int newY = u.second + Y[dir];
            if (!inside(newX, newY) || a[newX][newY] == '*' || used[newX][newY]) {
                continue;
            }
            if (dir % 2 == 1) {
                dp[newX][newY] = dp[u.first][u.second];
                used[newX][newY] = 1;
                q.push_front(pi(newX, newY));
            } else {
                pi foo = dp[u.first][u.second];
                foo.first += (newY < u.second);
                foo.second += (newY > u.second);
                if (foo.first <= x && foo.second <= y) {
                    dp[newX][newY] = foo;
                    used[newX][newY] = 1;
                    q.push_back(pi(newX, newY));
                } 
            }
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << used[i][j];
    //     }
    //     cout << endl;
    // }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            res += used[i][j];
        }
    }
    cout << res << endl;
    return 0;
}