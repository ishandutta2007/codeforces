#include<bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    vector<int> b(n - 1);
    for (int i = 0; i < n - 1; ++i)
    {
        b[i] = a[i + 1] - a[i];
    }
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    int ans = a[n - 1] - a[0];
    for (int i = 0; i < k - 1; ++i)
    {
        ans -= b[i];
    }
    cout << ans << endl;
    return 0;
}