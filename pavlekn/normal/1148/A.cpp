#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e9;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 2 * c;
    if (a == b)
    {
        ans += a + b;
    }
    else
    {
        ans += 2 * min(a, b) + 1;
    }
    cout << ans << endl;
    return 0;
}