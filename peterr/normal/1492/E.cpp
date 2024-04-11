#include <bits/stdc++.h>

using namespace std;

const int MAXN = 250000;
vector<int> a[MAXN];
int ans[MAXN];
bool good[MAXN];
int off[MAXN];

bool check(int n, int ind1, int ind2, int &x, int &y)
{
    x = y = -1;
    vector<pair<int, int>> req;
    for (int i = 1; i < n; i++)
    {
        int adj = off[i] - (a[0][ind1] != a[i][ind1]) - (a[0][ind2] != a[i][ind2]);
        if (adj > 2)
            return false;
        if (adj == 0)
            continue;
        if (adj == 1)
            req.push_back({a[i][ind1], a[i][ind2]});
        if (adj == 2)
        {
            if (x == -1)
            {
                x = a[i][ind1];
                y = a[i][ind2];
            }
            else if (x != a[i][ind1] || y != a[i][ind2])
            {
                return false;
            }
        }
    }
    if (req.empty())
    {
        if (x == -1)
        {
            x = a[0][ind1];
            y = a[0][ind2];
        }
        return true;
    }
    if (x != -1)
    {
        for (pair<int, int> pr : req)
        {
            if (pr.first != x && pr.second != y)
                return false;
        }
        return true;
    }
    bool valid = true;
    x = req[0].first;
    for (pair<int, int> pr : req)
    {
        if (pr.first == x)
            continue;
        if (y == -1)
            y = pr.second;
        else if (y != pr.second)
            valid = false;
    }
    if (y == -1)
        y = req[0].second;
    if (valid)
        return true;
    valid = true;
    x = -1;
    y = req[0].second;
    for (pair<int, int> pr : req)
    {
        if (pr.second == y)
            continue;
        if (x == -1)
            x = pr.first;
        else if (x != pr.first)
            valid = false;
    }
    if (x == -1)
        x = req[0].first;
    if (valid)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    fill(good, good + m, true);
    for (int i = 0; i < n; i++)
    {
        a[i] = vector<int>(m);
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] != a[0][j])
                good[j] = false;
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (good[j])
                continue;
            off[i] += a[i][j] != a[0][j];
        }
    }
    bool valid = false;
    vector<int> pos;
    for (int i = 0; i < m; i++)
    {
        ans[i] = a[0][i];
        if (!good[i])
            pos.push_back(i);
    }
    //int ha, haa;
    //check(n, 1, 4, ha, haa);
    if (pos.size() >= 4000)
    {
        cout << "No\n";
        return 0;
    }
    if (pos.size() >= 2)
    {
        for (int i : pos)
        {
            for (int j : pos)
            {
                if (i >= j)
                    continue;
                int x, y;
                x = y = -1;
                if (check(n, i, j, x, y))
                {
                    valid = true;
                    ans[i] = x;
                    ans[j] = y;
                    break;
                }
            }
            if (valid)
                break;
        }
    }
    else
        valid = true;
    if (!valid)
    {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    for (int i = 0; i < m; i++)
    {
        cout << ans[i] << " \n"[i == m - 1];
    }
    return 0;
}