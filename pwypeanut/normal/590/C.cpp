#include <bits/stdc++.h>
using namespace std;

int N, M, dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
char c[1005][1005];
int da[1005][1005], db[1005][1005], dc[1005][1005];
queue< pair< int, pair<int, int> > > Q;
bool vis[1005][1005];

bool valid(int x, int y) {
    if (x < 0 || x >= N) return 0;
    if (y < 0 || y >= M) return 0;
    if (c[x][y] == '#') return 0;
    return 1;
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%s", &c[i]);

    memset(da, 31, sizeof(da));
    memset(db, 31, sizeof(db));
    memset(dc, 31, sizeof(dc));

    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (c[i][j] == '1') {
                Q.push(make_pair(0, make_pair(i, j)));
                vis[i][j] = 1;
            }
        }
    }
    while (!Q.empty()) {
        int d = Q.front().first, x = Q.front().second.first, y = Q.front().second.second;
        Q.pop();
        da[x][y] = d;
        for (int i = 0; i < 4; i++) {
            int newx = x + dir[i][0], newy = y + dir[i][1];
            if (!valid(newx, newy)) continue;
            if (vis[newx][newy]) continue;
            vis[newx][newy] = 1;
            Q.push(make_pair(d + 1, make_pair(newx, newy)));
        }
    }


    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (c[i][j] == '2') {
                Q.push(make_pair(0, make_pair(i, j)));
                vis[i][j] = 1;
            }
        }
    }
    while (!Q.empty()) {
        int d = Q.front().first, x = Q.front().second.first, y = Q.front().second.second;
        Q.pop();
        db[x][y] = d;
        for (int i = 0; i < 4; i++) {
            int newx = x + dir[i][0], newy = y + dir[i][1];
            if (!valid(newx, newy)) continue;
            if (vis[newx][newy]) continue;
            vis[newx][newy] = 1;
            Q.push(make_pair(d + 1, make_pair(newx, newy)));
        }
    }


    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (c[i][j] == '3') {
                Q.push(make_pair(0, make_pair(i, j)));
                vis[i][j] = 1;
            }
        }
    }
    while (!Q.empty()) {
        int d = Q.front().first, x = Q.front().second.first, y = Q.front().second.second;
        Q.pop();
        dc[x][y] = d;
        for (int i = 0; i < 4; i++) {
            int newx = x + dir[i][0], newy = y + dir[i][1];
            if (!valid(newx, newy)) continue;
            if (vis[newx][newy]) continue;
            vis[newx][newy] = 1;
            Q.push(make_pair(d + 1, make_pair(newx, newy)));
        }
    }

    int ans = 2000000;

    // triangle case
    int ca = 100000000, ab = 100000000, bc = 100000000;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (c[i][j] == '1') ca = min(ca, dc[i][j] - 1);
            if (c[i][j] == '2') ab = min(ab, da[i][j] - 1);
            if (c[i][j] == '3') bc = min(bc, db[i][j] - 1);
        }
    }

    ans = min(ans, min(ca + ab, min(ca + bc, ab + bc)));
    //printf("triangle: %d + %d + %d = %d\n", ca, ab, bc, ans);

    // center case
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            ans = min(ans, max(0, da[i][j] - 1) + max(0, db[i][j] - 1) + max(0, dc[i][j] - 1) + 1);
        }
    }

    if (ans == 2000000) printf("-1\n");
    else printf("%d\n", ans);
}