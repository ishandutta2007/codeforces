#include<bits/stdc++.h>

using namespace std;

#define int long long



int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int p, q;
        cin >> p >> q;
        int ans1 = min(b, a / 2) * p + min(c, (a - 2 * min(b, a / 2)) / 2) * q;
        int ans2 = min(b, (a - 2 * min(c, a / 2)) / 2) * p + min(c, a / 2) * q;
        cout << max(ans1, ans2) << endl;
    }
    return 0;
}