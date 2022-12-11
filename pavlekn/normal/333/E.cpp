#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

const int MAXN = 3e3 + 2;

int x[MAXN];
int y[MAXN];

int dist(int i, int j)
{
    return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}

int d[MAXN][MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i] >> y[i];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            d[i][j] = dist(i, j);
        }
    }
    int cr;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            for (int k = j + 1; k < n; ++k)
            {
                cr = d[i][j];
                if (cr > d[i][k])
                {
                    cr = d[i][k];
                }
                if (cr > d[j][k])
                {
                    cr = d[j][k];
                }
                if (ans < cr)
                {
                    ans = cr;
                }
            }
        }
    }
    cout << setprecision(20) << sqrt(ans) / 2 << endl;
    return 0;
}