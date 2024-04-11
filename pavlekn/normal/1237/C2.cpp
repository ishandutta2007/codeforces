#include<bits/stdc++.h>

using namespace std;

#pragma GCC optimize("-O3")
#pragma GCC target("avx")

const int MAXN = 1e5 + 7;

int p[MAXN][3];

int m;

int solve(int k, vector<int> & a)
{
    if (k == 3)
    {
        return a[0];
    }
    vector<pair<int, int>> d;
    for (auto el : a)
    {
        d.push_back({p[el][k], el});
    }
    sort(d.begin(), d.end());
    a = {};
    for (auto el : d)
    {
        a.push_back(el.second);
    }
    vector<int> b;
    int n = a.size();
    vector<int> used(m);
    for (int i = 1; i < n; ++i)
    {
        if (p[a[i - 1]][k] == p[a[i]][k])
        {
            b.push_back(a[i - 1]);
            used[a[i - 1]] = true;
        }
        if (p[a[i - 1]][k] != p[a[i]][k])
        {
            b.push_back(a[i - 1]);
            used[a[i - 1]] = true;
            int ind = solve(k + 1, b);
            if (ind != -1)
                used[ind] = false;
            b.clear();
        }
        if (i == n - 1)
        {
            b.push_back(a[i]);
            used[a[i]] = true;
            int ind = solve(k + 1, b);
            if (ind != -1)
                used[ind] = false;
            b.clear();
        }
    }
    vector<int> c;
    for (int i = 0; i < n; ++i)
    {
        if (!used[a[i]])
        {
            c.push_back(a[i]);
        }
    }
    n = c.size();
    for (int i = 0; i < n / 2; ++i)
    {
        cout << c[2 * i] + 1 << " " << c[2 * i + 1] + 1 << endl;
    }
    if (n % 2)
    {
        return c[n - 1];
    }
    else
    {
        return -1;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    m = n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cin >> p[i][j];
        }
    }
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        a[i] = i;
    }
    solve(0, a);
    return 0;
}