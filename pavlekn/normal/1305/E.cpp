#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        a[i] = i + 1;
    }
    int ans = 0;
    for (int i = n - 2; i > 0; i -= 2)
    {
        ans += i;
    }
    if (m > ans)
    {
        cout << -1 << endl;
        return 0;
    }
    int MX = 1e9;
    for (int i = n - 1; i >= 0; --i)
    {
        int d = i / 2;
        if (ans - d >= m)
        {
            a[i] = MX;
            ans -= d;
        }
        else
        {
            while (ans > m)
            {
                a[i] += 2;
                --ans;
            }
            break;
        }
        MX -= (2 * n + 7);
    }
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}