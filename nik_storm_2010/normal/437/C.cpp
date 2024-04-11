#include <cstdio>
#include <vector>

using namespace std;
typedef pair <int, int> pii;
const int N = 1000 + 10;

int a[N], nom[N];
vector <int> g[N];
bool used[N];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), nom[i] = i;
    for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) if (a[nom[i]] < a[nom[j]]) swap(nom[i], nom[j]);
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = nom[i];
        used[x] = true;
        for (int j = 0; j < g[x].size(); j++) if (!used[g[x][j]]) ans += a[g[x][j]];
    }
    printf("%d\n", ans);
    return 0;
}