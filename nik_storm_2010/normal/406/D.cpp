#include <cstdio>
#include <vector>

using namespace std;
typedef long long ll;
const int N = 150000;
const int L = 19;

vector <int> edges[N];
ll x[N], y[N];
int anc[N][L], tin[N], tout[N], s[N], moment;

void dfs(int x, int last)
{
    tin[x] = ++moment;
    anc[x][0] = last;
    for (int i = 1; i < L; i++) anc[x][i] = anc[anc[x][i - 1]][i - 1];
    for (int i = 0; i < edges[x].size(); i++) if (edges[x][i] != last) dfs(edges[x][i], x);
    tout[x] = ++moment;
}

ll coef(int i, int j, int k)
{
    ll a = y[i] - y[j], b = x[j] - x[i], c = x[i] * y[j] - x[j] * y[i];
    return (a * x[k] + b * y[k] + c);
}

bool father(int x, int y)
{
    return (tin[x] <= tin[y] && tout[y] <= tout[x]);
}

int lca(int a, int b)
{
    if (father(a, b)) return a;
    if (father(b, a)) return b;
    for (int i = L - 1; i >= 0; i--) if (!father(anc[a][i], b)) a = anc[a][i];
    return anc[a][0];
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%I64d %I64d", &x[i], &y[i]);
    int cnt = 1;
    s[cnt] = n;
    for (int i = n - 1; i >= 1; i--)
    {
        s[++cnt] = i;
        while (cnt > 2 && coef(s[cnt], s[cnt - 2], s[cnt - 1]) < 0) swap(s[cnt - 1], s[cnt]), cnt--;
        edges[s[cnt]].push_back(s[cnt - 1]);
        edges[s[cnt - 1]].push_back(s[cnt]);
    }
    moment = 0, dfs(n, n);
    int quests;
    scanf("%d", &quests);
    for (int i = 1; i <= quests; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        printf("%d ", lca(x, y));
    }
    return 0;
}