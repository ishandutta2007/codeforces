#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, a1, b;
    cin >> n >> a1 >> b;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int can = 1;
    int ans = 0;
    for (int i = 0; 2 * i < n; ++i)
    {
        if (a[i] == a[n - i - 1] && a[i] != 2)
        {
        }
        else if (a[i] == a[n - i - 1])
        {
            if (i == n - i - 1)
            {
                ans += min(a1, b);
            }
            else
            {
                ans += 2 * min(a1, b);
            }
        }
        else if (a[i] == 2 && a[n - i - 1] != 2)
        {
            if (a[n - i - 1] == 1)
            {
                ans += b;
            }
            else
            {
                ans += a1;
            }
        }
        else if (a[i] != 2 && a[n - i - 1] == 2)
        {
            if (a[i] == 1)
            {
                ans += b;
            }
            else
            {
                ans += a1;
            }
        }
        else if (a[i] != 2 && a[n - i - 1] != 2 && a[i] != a[n - i - 1])
        {
            can = 0;
        }
    }
    if (!can)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
}