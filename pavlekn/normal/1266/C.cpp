#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    if (n == 1 && m == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    if (n == 1)
    {
        for (int i = 2; i <= m + 1; ++i)
        {
            cout << i << " ";
        }
        cout << endl;
        return 0;
    }
    if (m == 1)
    {
        for (int i = 2; i <= n + 1; ++i)
        {
            cout << i << endl;
        }
        return 0;
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << (m + i + 1) * (j + 1) << " ";
        }
        cout << endl;
    }
    return 0;
}