#include<bits/stdc++.h>

using namespace std;

const int MAXN = 3001;

int a[MAXN][MAXN];
int st[MAXN][MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long g0;
    int n, m, a1, b;
    int x, y, z;
    cin >> n >> m >> a1 >> b;
    cin >> g0 >> x >> y >> z;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            a[i][j] = g0;
            g0 = (g0 * x + y) % z;
        }
    }
    long long ans = 0;
    deque<int> q;
    for (int i = 0; i < n; ++i)
    {
        q = {};
        for (int j = 0; j < m; ++j)
        {
            while (!q.empty() && a[i][q.back()] >= a[i][j])
            {
                q.pop_back();
            }
            q.push_back(j);
            if (q.front() <= j - b)
            {
                q.pop_front();
            }
            if (j >= b - 1)
            {
                st[i][j - b + 1] = a[i][q.front()];
            }
        }
    }
    for (int l = 0; l + b <= m; ++l)
    {
        q = {};
        for (int i = 0; i < n; ++i)
        {
            while (!q.empty() && st[q.back()][l] >= st[i][l])
            {
                q.pop_back();
            }
            q.push_back(i);
            if (q.front() <= i - a1)
            {
                q.pop_front();
            }
            if (i >= a1 - 1)
            {
                ans += st[q.front()][l];
            }
        }
    }
    cout << ans << endl;
    return 0;
}