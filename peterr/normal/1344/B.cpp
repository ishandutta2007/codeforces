#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
bool b[MAXN][MAXN];
int pref[MAXN];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool visited[MAXN][MAXN];

int query(int l, int r)
{
    if (l == 0)
        return pref[r];
    return pref[r] - pref[l - 1];
}

bool check(int n, int m, bool &em)
{
    bool ans = true;
    for (int i = 0; i < n; i++)
    {
        pref[0] = b[i][0];
        int l, r;
        r = l = -1;
        for (int j = 1; j < m; j++)
        {
            pref[j] = pref[j - 1] + b[i][j];
            if (b[i][j])
                r = j;
        }
        for (int j = m - 1; j >= 0; j--)
            if (b[i][j])
                l = j;
        if (l != -1 && query(l, r) != r - l + 1)
            ans = false;
        if (pref[m - 1] == 0)
            em = true;
    }
    return ans;
}

void tr(int n, int m)
{
    for (int i = 0; i < max(n, m); i++)
        for (int j = i + 1; j < max(n, m); j++)
            swap(b[i][j], b[j][i]);
}

bool isValid(int r, int c, int n, int m)
{
    return r >= 0 && r < n && c >= 0 && c < m;
}

void dfs(int r, int c, int n, int m)
{
    visited[r][c] = true;
    for (int i = 0; i < 4; i++)
    {
        int newr = r + dx[i];
        int newc = c + dy[i];
        if (isValid(newr, newc, n, m) && !visited[newr][newc] && b[newr][newc])
            dfs(newr, newc, n, m);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
            b[i][j] = s[j] == '#';
    }
    bool emrow = false;
    bool emcol = false;
    if (!check(n, m, emrow))
    {
        cout << -1 << endl;
        return 0;
    }
    tr(n, m);
    if (!check(m, n, emcol))
    {
        cout << -1 << endl;
        return 0;
    }
    tr(n, m);
    if (emrow ^ emcol)
    {
        cout << -1 << endl;
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (b[i][j] && !visited[i][j])
            {
                ans++;
                dfs(i, j, n, m);
            }
        }
    }
    cout << ans << endl;
    return 0;
}