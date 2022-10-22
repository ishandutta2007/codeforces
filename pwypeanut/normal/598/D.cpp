#include <bits/stdc++.h>
using namespace std;

int N, M, K, cur, dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}}, col[1005][1005], cnt[1000005];
char c[1005][1005];
bool vis[1005][1005];

bool check(int x, int y) {
    if (x < 0 || x >= N) return 0;
    if (y < 0 || y >= M) return 0;
    if (c[x][y] == '*') return 0;
    return 1;
}

void dfs(int x, int y, int com) {
    if (vis[x][y]) return;
    else vis[x][y] = 1;
    col[x][y] = com;
    for (int i = 0; i < 4; i++) {
        int newx = x + dir[i][0], newy = y + dir[i][1];
        if (!check(newx, newy)) continue;
        dfs(newx, newy, com);
    }
}

int main() {
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 0; i < N; i++) scanf("%s", &c[i]);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (c[i][j] == '.' && !vis[i][j]) {
                dfs(i, j, cur);
                cur++;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (c[i][j] == '.') continue;
            for (int k = 0; k < 4; k++) {
                int newx = i + dir[k][0], newy = j + dir[k][1];
                if (!check(newx, newy)) continue;
                cnt[col[newx][newy]]++;
            }
        }
    }
    for (int i = 0; i < K; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", cnt[col[x-1][y-1]]);
    }
}