#include <cstdio>
#include <algorithm>

using namespace std;
typedef pair <int, int> pii;
const int N = 2e3;
const int VOID = 2e9;

pii go[N][N];
int n, m;
char a[N][N];

bool dfs(int x, int y, int px, int py)
{
    if (x < 0) x += n;
    if (x >= n) x -= n;
    if (y < 0) y += m;
    if (y >= m) y -= m;
    if (a[x][y] == '#') return false;
    if (go[x][y].first != VOID) return (!(px == go[x][y].first && py == go[x][y].second));
    go[x][y].first = px, go[x][y].second = py;
    bool res = false;
    res |= dfs(x + 1, y, px + 1, py);
    res |= dfs(x - 1, y, px - 1, py);
    res |= dfs(x, y + 1, px, py + 1);
    res |= dfs(x, y - 1, px, py - 1);
    return res;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", a[i]);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) go[i][j] = make_pair(VOID, VOID);
    int sx, sy;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (a[i][j] == 'S') sx = i, sy = j;
    a[sx][sy] = '.';
    puts((dfs(sx, sy, sx, sy)) ? "Yes" : "No");
    return 0;
}