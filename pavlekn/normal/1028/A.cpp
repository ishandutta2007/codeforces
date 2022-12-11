#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int x1, y1, x2, y2;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] == 'B')
            {
                x2 = i + 1;
                y2 = j + 1;
            }
        }
    }
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = m - 1; j >= 0; --j)
        {
            if (a[i][j] == 'B')
            {
                x1 = i + 1;
                y1 = j + 1;
            }
        }
    }
    cout << (x1 + x2) / 2 << " " << (y1 + y2) / 2 << endl;
}