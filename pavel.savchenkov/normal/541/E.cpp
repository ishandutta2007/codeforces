#include <bits\stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef vector<int> Vint;
typedef long double ld;

bool check_cycle(int x, int p, const vector<Vint> &graph,
                 vector<char> &used, Vint &color)
{
    used[x] = 1;

    bool ok = false;
    for (int dest : graph[x])
    if (!used[dest])
    {
        color[dest] = 3 ^ color[x];
        ok |= check_cycle(dest, x, graph, used, color);
    }
    return ok;
}

bool has_cycle(const vector<Vint> &graph)
{
    int n = (int)graph.size() - 1;
    vector<char> used(n + 1, 0);
    Vint color(n + 1, 0);

    for (int i = 1; i <= n; i++)
    if (!used[i])
    {
        color[i] = 1;
        check_cycle(i, -1, graph, used, color);
    }

    for (int i = 1; i <= n; i++)
    for (int dest : graph[i])
    if (color[dest] == color[i])
        return true;
    return false;
}

int bfs(int x, const vector<Vint> &graph,
         vector<char> &used, Vint &comp, Vint &dp, int &len,
         int toset)
{
    dp[x] = 0;

    Vint q;
    int l = 0, r = 1;
    q.pb(x);
    used[x] = 1;
    if (toset == 1)
        comp.pb(x);

    while (r > l)
    {
        int cur = q[l]; l++;

        for (int dest : graph[cur])
        if (!used[dest])
        {
            dp[dest] = dp[cur] + 1;
            q.pb(dest);
            if (toset == 1)
                comp.pb(dest);
            r++;
            used[dest] = 1;
        }
    }

    len = dp[q.back()];
    return q.back();
}

int getans(const vector<Vint> &graph)
{
    int n = (int)graph.size() - 1;
    int comps = 0;

    vector<char> used(n + 1, 0);
    Vint comp;
    Vint dp(n + 1, 0);

    int ans = 0;
    for (int i = 1; i <= n; i++)
    if (!used[i])
    {
        comp.clear();
        int len;
        int u = bfs(i, graph, used, comp, dp, len, 1);

        for (int x : comp)
            used[x] = 0;

        int clen = 0;
        for (int x : comp)
        {
            bfs(x, graph, used, comp, dp, len, 0);
            for (int y : comp)
                used[y] = 0;
            clen = max(clen, len);
        }

        for (int x : comp)
            used[x] = 1;

        ans += clen;
        comps++;
    }

    return ans;
}

void solve(int n)
{
    vector<Vint> graph(n + 1);
    int x, y;

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        scanf(" %d %d", &x, &y);
        graph[x].pb(y);
        graph[y].pb(x);
    }

    if (has_cycle(graph))
        printf("-1\n");
    else
        printf("%d\n", getans(graph));
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n;
    while (cin >> n)
        solve(n);
}