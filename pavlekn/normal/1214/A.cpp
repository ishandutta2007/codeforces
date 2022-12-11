#include<bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e6 + 5;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, d, e;
    cin >> n >> d >> e;
    e *= 5;
    int ans = n;
    for (int i = 0; i < MAXN; ++i)
    {
        if (e * i <= n)
        {
            ans = min(ans, (n - e * i) % d);
        }
    }
    cout << ans << endl;
    return 0;
}