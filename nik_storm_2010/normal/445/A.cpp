#include <cstdio>

using namespace std;
const int N = 200;

char a[N][N];
int n, m;

void dfs(int x, int y, int pos)
{
    if (0 <= x && x < n && 0 <= y && y < m); else return;
    if (a[x][y] != '.') return;
    if (pos == 0) a[x][y] = 'B'; else a[x][y] = 'W';
    dfs(x + 1, y, 1 - pos);
    dfs(x - 1, y, 1 - pos);
    dfs(x, y + 1, 1 - pos);
    dfs(x, y - 1, 1 - pos);
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", a[i]);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) dfs(i, j, 1);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
    {
        printf("%c", a[i][j]);
        if (j == m - 1) printf("\n");
    }
    return 0;
}