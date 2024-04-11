#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int ans = a[n - 1];
    int mn = a[n - 1];
    for (int i = n - 2; i >= 0; --i)
    {
        mn = min(mn - 1, a[i]);
        ans += max(0ll, mn);
    }
    cout << ans << endl;
    return 0;
}