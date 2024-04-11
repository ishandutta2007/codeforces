#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

const int N = 20;
const int INF = 1e9;

const int X[] = {1, 2, 2, 1, -1, -2, -2, -1};
const int Y[] = {2, 1, -1, -2, -2, -1, 1, 2};

int n;
int a[N][N];

struct State
{
    int id, x, y, numPassed;

    State(int id = 0, int x = 0, int y = 0, int numPassed = 0) : id(id), x(x), y(y), numPassed(numPassed) {}

    bool operator < (const State &u) const {
        return id > u.id;
    }
};

bool used[3][N][N][N * N];
pi dp[3][N][N][N * N];

bool inside(int u, int v) {
    return (u >= 0 && u < n && v >= 0 && v < n);
}

pi rev(pi u) {
    return pi(-u.first, -u.second);
}

void go(priority_queue<pair<pi, State > > &q, State &u, int xx, int yy) {
    int newX = u.x;
    int newY = u.y;
    pi dpVal = dp[u.id][u.x][u.y][u.numPassed];
    while (1) {
        newX += xx;
        newY += yy;
        if (!inside(newX, newY)) {
            break;
        }
        int newNum = u.numPassed + (a[newX][newY] == (u.numPassed + 1));
        if (used[u.id][newX][newY][newNum]) continue;
        if (dp[u.id][newX][newY][newNum] > pi(dpVal.first + 1, dpVal.second)) {
            dp[u.id][newX][newY][newNum] = pi(dpVal.first + 1, dpVal.second);
            q.push(make_pair(rev(dp[u.id][newX][newY][newNum]), State(u.id, newX, newY, newNum)));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int x = -1, y = -1;
    int xx = -1, yy = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) {
                x = i;
                y = j;
            }
            if (a[i][j] == n * n) {
                xx = i;
                yy = j;
            }
        }
    }
    for (int id = 0; id < 3; id++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int numPassed = 0; numPassed <= n * n; numPassed++) {
                    dp[id][i][j][numPassed] = pi(INF, INF);
                }
            }
        }
    }
    priority_queue<pair<pi, State > >  q;
    dp[0][x][y][1] = dp[1][x][y][1] = dp[2][x][y][1] = pi(0, 0);
    q.push(make_pair(pi(0, 0), State(0, x, y, 1)));
    q.push(make_pair(pi(0, 0), State(1, x, y, 1)));
    q.push(make_pair(pi(0, 0), State(2, x, y, 1)));
    while (!q.empty()) {
        State u = q.top().second;
        // cout << "res " << -q.top().first.first << " " << -q.top().first.second << endl;
        // cout << u.id << " " << u.x << " " << u.y << " " << u.numPassed << endl;
        q.pop();
        if (used[u.id][u.x][u.y][u.numPassed]) {
            continue;
        }
        pi dpVal = dp[u.id][u.x][u.y][u.numPassed];
        used[u.id][u.x][u.y][u.numPassed] = 1;
        for (int off = 1; off <= 2; off++) {
            int newId = (off + u.id) % 3;
            if (used[newId][u.x][u.y][u.numPassed]) continue;
            if (dp[newId][u.x][u.y][u.numPassed] > pi(dpVal.first + 1, dpVal.second + 1)) {
                dp[newId][u.x][u.y][u.numPassed] = pi(dpVal.first + 1, dpVal.second + 1);
                q.push(make_pair(rev(dp[newId][u.x][u.y][u.numPassed]), State(newId, u.x, u.y, u.numPassed)));
            }
        }
        if (u.id == 0) {
            for (int i = 0; i < 8; i++) {
                int newX = u.x + X[i];
                int newY = u.y + Y[i];
                if (!inside(newX, newY)) {
                    continue;
                }
                int newNum = u.numPassed + (a[newX][newY] == (u.numPassed + 1));
                if (used[u.id][newX][newY][newNum]) continue;
                if (dp[u.id][newX][newY][newNum] > pi(dpVal.first + 1, dpVal.second)) {
                    dp[u.id][newX][newY][newNum] = pi(dpVal.first + 1, dpVal.second);
                    q.push(make_pair(rev(dp[u.id][newX][newY][newNum]), State(u.id, newX, newY, newNum)));
                }
            }
        } else if (u.id == 1) {
            go(q, u, 0, 1);
            go(q, u, 0, -1);
            go(q, u, 1, 0);
            go(q, u, -1, 0);
        } else {
            go(q, u, 1, 1);
            go(q, u, 1, -1);
            go(q, u, -1, 1);
            go(q, u, -1, -1);
        }
    }
    // for (int id = 0; id < 3; id++) {
    //     for (int i = 0; i < n; i++) {
    //         for (int j = 0; j < n; j++) {
    //             for (int numPassed = 1; numPassed <= n * n; numPassed++) {
    //                 cout << id << " " << i << " " << j << " " << numPassed << " " << dp[id][i][j][numPassed].first << " " << dp[id][i][j][numPassed].second << endl;
    //             }
    //         }
    //     }
    // }
    pi res = pi(INF, INF);
    for (int i = 0; i < 3; i++) {
        res = min(res, dp[i][xx][yy][n * n]);
    }
    cout << res.first << " " << res.second << endl;
    return 0;
}