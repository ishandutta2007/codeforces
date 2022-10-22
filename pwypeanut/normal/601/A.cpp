#include <bits/stdc++.h>
using namespace std;

int N, M, arr[405][405], d[405];
queue<int> Q;
bool vis[405];

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        x--;y--;
        arr[x][y] = arr[y][x] = 1;
    }
    int ans = 2000000000;
    d[0] = 0;
    Q.push(0);
    vis[0] = 1;
    while (!Q.empty()) {
        int pos = Q.front();
        Q.pop();
        if (pos == N-1) {
            ans = d[N-1];
            break;
        }
        for (int i = 0; i < N; i++) {
            if (arr[pos][i] == 1 && vis[i] == 0) {
                vis[i] = 1;
                d[i] = d[pos] + 1;
                Q.push(i);
            }
        }
    }
    if (ans == 2000000000) {
        printf("-1\n");
        return 0;
    }
    memset(vis, 0, sizeof(vis));
    memset(d, 0, sizeof(d));
    while (!Q.empty()) Q.pop();
    d[0] = 0;
    Q.push(0);
    vis[0] = 1;
    bool found = 0;
    while (!Q.empty()) {
        int pos = Q.front();
        Q.pop();
        if (pos == N-1) {
            ans = max(d[N-1], ans);
            found = 1;
            break;
        }
        for (int i = 0; i < N; i++) {
            if (arr[pos][i] == 0 && vis[i] == 0) {
                vis[i] = 1;
                d[i] = d[pos] + 1;
                Q.push(i);
            }
        }
    }
    if (!found) {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", ans);
}