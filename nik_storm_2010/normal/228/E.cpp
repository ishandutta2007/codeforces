#include<cstdio>
#include<vector>

using namespace std;
const int N = 200;

int st[N], n, m, k;
vector <int> e[N], w[N];
bool used[N], make[N];

bool dfs(int x, bool need)
{
    st[++k] = x;
    used[x] = true;
    make[x] = need;
    bool res = true;
    for (int i = 0; i < e[x].size(); i++)
    {
        int t = e[x][i], p = w[x][i];
        if (!used[t])
        {
            if ((make[x] && p == 1) || (!make[x] && p == 0))  res &= dfs(t, true); else res &= dfs(t, false);
        }
        if (make[x] && p == 1 && !make[t]) return false;
        if (!make[x] && p == 1 && make[t]) return false;
        if (!make[x] && p == 0 && !make[t]) return false;
        if (make[x] && p == 0 && make[t]) return false;
    }
    return res;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        e[a].push_back(b);
        w[a].push_back(c);
        e[b].push_back(a);
        w[b].push_back(c);
    }
    for (int i = 1; i <= n; i++)
    {
        if (used[i]) continue;
        k = 0;
        bool may = dfs(i, true);
        if (may) continue;
        for (int j = 1; j <= k; j++) used[st[j]] = false, make[st[j]] = false;
        may = dfs(i, false);
        if (!may)
        {
            printf("Impossible\n");
            return 0;
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) if (make[i]) res++;
    printf("%d\n", res);
    for (int i = 1; i <= n; i++) if (make[i]) printf("%d ", i);
    return 0;
}