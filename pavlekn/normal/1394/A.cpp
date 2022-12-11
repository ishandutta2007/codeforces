#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, d, m;
    cin >> n >> d >> m;
    int ans = 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    ans += a[0];
    int cnt = 0;
    int cur = 0;
    vector<int> b(n + 1);
    for (int i = 0; i < n; ++i)
    {
        if (a[i] <= m)
        {
            b[cnt] = cur;
            ++cnt;
            cur += a[i];
        }
    }
    b[cnt] = cur;
    for (int i = 1; i <= n; ++i)
    {
        if (b[i] == 0)
        {
            b[i] = b[i - 1];
        }
    }
    int sm = 0;
    ans = max(ans, b[n]);
    for (int i = 0; i < n; ++i)
    {
        sm += a[i];
        if (a[i] <= m)
        {
            break;
        }
        if (i * (d + 1) < n)
        {
            ans = max(ans, sm + b[n - 1 - i * (d + 1)]);
        }
    }
    cout << ans << endl;
    return 0;
}