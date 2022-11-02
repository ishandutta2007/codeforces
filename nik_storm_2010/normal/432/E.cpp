#include <cstdio>
#include <memory.h>
#include <algorithm>

using namespace std;
const int N = 200;

char a[N][N];

bool maybe(int x1, int y1, int x2, int y2, char c)
{
    for (int i = x1; i <= x2; i++) for (int j = y1; j <= y2; j++)
    {
        if (a[i][j] != '$') return false;
        if (a[i - 1][j] == c) return false;
        if (a[i + 1][j] == c) return false;
        if (a[i][j - 1] == c) return false;
        if (a[i][j + 1] == c) return false;
    }
    return true;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    memset(a, '$', sizeof(a));
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (a[i][j] == '$') for (char c = 'A'; ; c++)
    {
         if (!maybe(i, j, i, j, c)) continue;
         int x1 = i, y1 = j;
         for (int x = 1; x <= min(n - i, m - j); x++)
         {
             if (!maybe(i, j, i + x, j + x, c)) break;
             bool good = true;
             for (char p = 'A'; p < c; p++) if (maybe(i, j + x, i, j + x, p)) good = false;
             if (!good) break;
             x1++, y1++;
         }
         for (int x = i; x <= x1; x++) for (int y = j; y <= y1; y++) a[x][y] = c;
         break;
    }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
    {
        printf("%c", a[i][j]);
        if (j == m) printf("\n");
    }
    return 0;
}