#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int n,m,ans;

char a[1005][1005];

bool flag[1005][1005];
bool R[1005];
bool C[1005];

pair <int, int> Q[1000005];

void bfs(int i, int j)
{
    int f = 0;
    int r = 0;
    Q[++r] = mp(i, j);
    flag[i][j] = true;
    while (r > f)
    {
        f++;
        int x = Q[f].fi;
        int y = Q[f].se;
        for (int d = 0; d <= 3; d++)
        {
            int u = x + dx[d];
            int v = y + dy[d];
            if (!flag[u][v] && a[u][v] == '#')
            {
                Q[++r] = mp(u, v);
                flag[u][v] =true;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("file.inp","r",stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    {
        cin >> a[i][j];
        if (a[i][j] == '#')
        {
            R[i] = true;
            C[j] = true;
        }
    }
    bool R_left = false;
    bool C_left = false;
    for (int i = 1; i <= n; i++)
    {
        if (!R[i]) R_left = true;
    }
    for (int i = 1; i <= m; i++)
    {
        if (!C[i]) C_left = true;
    }
    if (R_left != C_left) return cout << -1, 0;
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == '#' && a[i][j - 1] != '#') cnt++;
        }
        if (cnt > 1) return cout << -1, 0;
    }
    for (int j = 1; j <= m; j++)
    {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i][j] == '#' && a[i - 1][j] != '#') cnt++;
        }
        if (cnt > 1) return cout << -1, 0;
    }
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
    {
        if (a[i][j] == '#' && !flag[i][j]) bfs(i, j), ans++;
    }
    cout << ans;
    return 0;
}