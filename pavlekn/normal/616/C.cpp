#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2007;

const int MM = 1e6 + 7;

#define int long long

int coun;

char a[MAXN][MAXN];
int used[MAXN][MAXN];
int dp[MAXN][MAXN];
int num[MAXN][MAXN];

int aa[MM];

int nm = 0;

int n, m;

int set1(int i, int j, int val)
{
    dp[i][j] = val;
    dp[i][j] %= 10;
    num[i][j] = nm;
    aa[nm] = val;
}

int dfs(int i, int j)
{
    if (used[i][j])
    {
        return 0;
    }
    ++coun;
    used[i][j] = true;
    if (i > 0 && a[i - 1][j])
    {
        dfs(i - 1, j);
    }
    if (j > 0 && a[i][j - 1])
    {
        dfs(i, j - 1);
    }
    if (i < n - 1 && a[i + 1][j])
    {
        dfs(i + 1, j);
    }
    if (j < m - 1 && a[i][j + 1])
    {
        dfs(i, j + 1);
    }
    if (i > 0 && a[i - 1][j])
    {
        set1(i - 1, j, coun);
    }
    if (j > 0 && a[i][j - 1])
    {
        set1(i, j - 1, coun);
    }
    if (i < n - 1 && a[i + 1][j])
    {
        set1(i + 1, j, coun);
    }
    if (j < m - 1 && a[i][j + 1])
    {
        set1(i, j + 1, coun);
    }
    set1(i, j, coun);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            char c;
            cin >> c;
            if (c == '.')
            {
                a[i][j] = 1;
            }
            else
            {
                a[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j])
            {
                ++nm;
                coun = 0;
                dfs(i, j);
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] == 0)
            {
                int ans = 1;
                set<int> nms;
                if (i > 0 && a[i - 1][j])
                {
                    nms.insert(num[i - 1][j]);
                }
                if (i < n - 1 && a[i + 1][j])
                {
                    nms.insert(num[i + 1][j]);
                }
                if (j > 0 && a[i][j - 1])
                {
                    nms.insert(num[i][j - 1]);
                }
                if (j < m - 1 && a[i][j + 1])
                {
                    nms.insert(num[i][j + 1]);
                }
                for (auto el : nms)
                {
                    ans += aa[el];
                }
                cout << (ans % 10 + 10) % 10;
            }
            else
            {
                cout << '.';
            }
        }
        cout << endl;
    }
    return 0;
}