#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int a[MAXN][MAXN];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        long long ans = 0;
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < m / 2; j++)
            {
                int x1 = a[i][j];
                int x2 = a[i][m - j - 1];
                int x3 = a[n - i - 1][j];
                int x4 = a[n - i - 1][m - j - 1];
                int mn1 = x1;
                int mn2 = x2;
                if (mn1 > mn2)
                    swap(mn1, mn2);
                if (x3 < mn1)
                {
                    mn2 = mn1;
                    mn1 = x3;
                }
                else if (x3 < mn2)
                    mn2 = x3;
                if (x4 < mn1)
                {
                    mn2 = mn1;
                    mn1 = x4;
                }
                else if (x4 < mn2)
                    mn2 = x4;
                ans += abs(x1 - mn2);
                ans += abs(x2 - mn2);
                ans += abs(x3 - mn2);
                ans += abs(x4 - mn2);
            }
        }
        if (n & 1)
        {
            for (int i = 0; i < m / 2; i++)
            {
                ans += abs(a[n / 2][i] - a[n / 2][m - i - 1]);
            }
        }
        if (m & 1)
        {
            for (int i = 0; i < n / 2; i++)
            {
                ans += abs(a[i][m / 2] - a[n - i - 1][m / 2]);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}