#include <cstdio>
#include <cstdlib>
#include <set>

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int N = 300 + 5;

int a[N][N], l[N][N], r[N][N], d[N][N], u[N][N], tp, tu, td, ans, r1, r2, c1, c2, t;

int cost(int x, int y)
{
    if (x == y) return tp;
    if (x < y) return tu;
    if (x > y) return td;
}

void update(int x1, int y1, int x2, int y2)
{
    int cur = (r[x1][y2 - 1] - r[x1][y1 - 1]) + (d[x2 - 1][y2] - d[x1 - 1][y2]) + (l[x2][y2] - l[x2][y1]) + (u[x2][y1] - u[x1][y1]);
    if (abs(cur - t) < abs(ans - t))
    {
        ans = cur;
        r1 = x1, c1 = y1;
        r2 = x2, c2 = y2;
    }
}

int main()
{
    int n, m;
    scanf("%d %d %d", &n, &m, &t);
    scanf("%d %d %d", &tp, &tu, &td);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
    {
        l[i][j] = l[i][j - 1] + cost(a[i][j], a[i][j - 1]);
        r[i][j] = r[i][j - 1] + cost(a[i][j], a[i][j + 1]);
        d[i][j] = d[i - 1][j] + cost(a[i][j], a[i + 1][j]);
        u[i][j] = u[i - 1][j] + cost(a[i][j], a[i - 1][j]);
    }
    ans = 2e9;
    for (int x1 = 1; x1 <= n; x1++) for (int x2 = x1 + 2; x2 <= n; x2++)
    {
        set <pii> base;
        base.insert(make_pair(-r[x1][1 - 1] - l[x2][1] + u[x2][1] - u[x1][1], 1));
        for (int y = 3; y <= m; y++)
        {
            int cur = t - (r[x1][y - 1] + d[x2 - 1][y] - d[x1 - 1][y] + l[x2][y]);
            set <pii>::iterator it = base.lower_bound(make_pair(cur, 0));
            if (it != base.end()) update(x1, it -> second, x2, y);
            if (it != base.begin())
            {
                it--;
                update(x1, it -> second, x2, y);
            }
            base.insert(make_pair(-r[x1][y - 2] - l[x2][y - 1] + u[x2][y - 1] - u[x1][y - 1], y - 1));
        }
    }
    printf("%d %d %d %d\n", r1, c1, r2, c2);
    return 0;
}