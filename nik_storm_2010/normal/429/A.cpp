#include <cstdio>
#include <vector>

using namespace std;
const int N = 200000;

vector <int> edges[N];
int cur[N], goal[N], ans;
bool used[N];

int dfs(int x, int prev, int now, int next)
{
    int here = cur[x] ^ now;
    if (here != goal[x])
    {
        used[x] = true;
        ans++;
        now ^= 1;
    }
    for (int i = 0; i < edges[x].size(); i++) if (edges[x][i] != prev)
        dfs(edges[x][i], x, next, now);
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) scanf("%d", &cur[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &goal[i]);
    ans = 0;
    dfs(1, 0, 0, 0);
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++) if (used[i]) printf("%d\n", i);
    return 0;
}