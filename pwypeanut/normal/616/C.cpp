#include <bits/stdc++.h>
using namespace std;

int N, M, col[1005][1005], sze[1000005], cur, dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
char c[1005][1005];
bool vis[1005][1005];

bool valid(int x, int y) {
    if (x < 0 || x >= N) return false;
    if (y < 0 || y >= M) return false;
    if (c[x][y] == '*') return false;
    return true;
}

void dfs(int x, int y) {
    if (vis[x][y]) return;
    else vis[x][y] = 1;
    col[x][y] = cur;
    for (int i = 0; i < 4; i++) {
        int newx = x + dir[i][0], newy = y + dir[i][1];
        if (!valid(newx, newy)) continue;
        dfs(newx, newy);
    }
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%s", &c[i]);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!vis[i][j] && c[i][j] == '.') {
                dfs(i, j);
                cur++;
            }
        }
    }
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) if (c[i][j] == '.') sze[col[i][j]]++;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (c[i][j] == '.') {
                printf(".");
                continue;
            }
            set<int> S;
            for (int k = 0; k < 4; k++) {
                int newx = i + dir[k][0], newy = j + dir[k][1];
                if (!valid(newx, newy)) continue;
                S.insert(col[newx][newy]);
            }
            int ans = 1;
            for (set<int>::iterator it = S.begin(); it != S.end(); it++) ans += sze[*it];
            printf("%d", ans%10);
        }
        printf("\n");
    }
}