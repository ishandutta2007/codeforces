#include <bits/stdc++.h>

using namespace std;

#define int long long

#pragma GCC optimize("-O3")

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        int n, x, a, b;
        cin >> n >> x >> a >> b;
        int ans = min(n - 1, abs(a - b) + x);
        cout << ans << endl;
    }
    return 0;
}