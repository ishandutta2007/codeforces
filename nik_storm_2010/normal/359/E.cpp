#include<cstdio>

using namespace std;
const int N = 500 + 10;
const int M = 1000000 + 10;

int a[N][N], n, sum, cnt;
bool used[N][N];
char res[M];

void add(char c) {
    cnt++;
    res[cnt] = c;
}

int have(int x, int y, int dx, int dy) {
    x += dx;
    y += dy;
    while (x > 0 && x <= n && y > 0 && y <= n) {
        if (used[x][y]) return -1;
        if (a[x][y] == 1) return 1;
        x += dx;
        y += dy;
    }
    return -1;
}

void dfs(int x, int y, char dir) {
    if (a[x][y] == 0) { add('1'); sum++; }
    a[x][y] = 1;
    used[x][y] = true;
    if (have(x, y, +1, 0) != -1) { add('D'); dfs(x + 1, y, 'U'); }
    if (have(x, y, -1, 0) != -1) { add('U'); dfs(x - 1, y, 'D'); }
    if (have(x, y, 0, +1) != -1) { add('R'); dfs(x, y + 1, 'L'); }
    if (have(x, y, 0, -1) != -1) { add('L'); dfs(x, y - 1, 'R'); }
    sum--;
    add('2');
    if (dir != '$') add(dir);
}

int main() {
    int x1, y1;
    scanf("%d %d %d", &n, &x1, &y1);
    sum = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        scanf("%d", &a[i][j]);
        sum += a[i][j];
    }
    dfs(x1, y1, '$');
    if (sum == 0) {
        printf("YES\n");
        for (int i = 1; i <= cnt; i++) printf("%c", res[i]);
    }
    else printf("NO\n");
    return 0;
}