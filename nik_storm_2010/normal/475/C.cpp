#include <cstdio>

using namespace std;
const int N = 2000;
const int INF = 2e9;

char a[N][N];
int sum[N][N];

int get(int x1, int y1, int x2, int y2) {
    return (sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1]);
}

int main() {
    int n, m;
    scanf("%d %d\n", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", a[i] + 1);
    int sx, sy, cnt = 0;
    for (int i = n; i >= 1; i--) for (int j = m; j >= 1; j--) if (a[i][j] == 'X') sx = i, sy = j, cnt++;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (a[i][j] == 'X');
    int ans = INF;
    for (int lx = 1; lx <= n - sx + 1; lx++) for (int ly = 1; ly <= m - sy + 1; ly++) {
        if (lx * ly >= ans) continue;
        int x = sx, y = sy;
        int all = get(x, y, x + lx - 1, y + ly - 1);
        if (all != lx * ly) continue;
        while (true) {
            bool down, right;
            if (x + lx > n || get(x + lx, y, x + lx, y + ly - 1) != ly) down = false; else down = true;
            if (y + ly > m || get(x, y + ly, x + lx - 1, y + ly) != lx) right = false; else right = true;
            if (down == right) break;
            if (down) all += ly, x++; else all += lx, y++;
        }
        if (all == cnt) ans = lx * ly;
    }
    if (ans == INF) ans = -1;
    printf("%d\n", ans);
    return 0;
}