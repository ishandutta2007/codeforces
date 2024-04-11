#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;

int n, m, k;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
vector< pair< int, pair<int, int> > > ans;
bool used[50][50];

bool check(int x, int y)
{
    return x >= 0 && y >= 0 && x < n && y < m;
}

char a[50][50];

int dfs(int v1, int v2)
{
    used[v1][v2] = true;
    int d = 1;
    bool t = true;
    for (int i = 0; i < 4; i++)
    {
        int u1 = v1 + dx[i];
        int u2 = v2 + dy[i];
        if (!check(u1, u2))
            return -1;
        if (a[u1][u2] == '.' && !used[u1][u2])
        {
            int k = dfs(u1, u2);
            if (k == -1)
                t = false;
            d += k;
        }
    }
    if (!t)
        return -1;
    return d;
}

int dfs1(int x, int y)
{
    a[x][y] = '*';
    for (int i = 0; i < 4; i++)
    {
        int u1 = x + dx[i];
        int u2 = y + dy[i];
        if (a[u1][u2] == '.')
            dfs1(u1, u2);
    }
    return 0;
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!used[i][j] && a[i][j] == '.')
            {
                int k = dfs(i, j);
                if (k != -1)
                    ans.push_back(make_pair(k, make_pair(i, j)));
            }
    sort(ans.begin(),ans.end());
    int anss = 0;
    for (int i = 0; i < ans.size() - k; i++)
    {
        anss += ans[i].first;
        dfs1(ans[i].second.first, ans[i].second.second);
    }
    cout << anss << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << a[i][j];
        cout << endl;
    }
    return 0;
}