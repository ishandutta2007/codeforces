#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int pos = n / 2;
    int ans = 0;
    if (a[pos] < s)
    {
        for (int i = pos; i < n; ++i)
        {
            ans += max(1ll * 0, s - a[i]);
        }
    }
    else
    {
        for (int i = 0; i <= pos; ++i)
        {
            ans += max(1ll * 0, a[i] - s);
        }
    }
    cout << ans << endl;
}