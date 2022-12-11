#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int ans = 0;
    int nn = n;
    while (n >= b)
    {
        ans += (n - b) / (b - c) + 1;
        n = c + (n - b) % (b - c);
    }
    ans += n / a;
    cout << max(ans, nn / a) << endl;
    return 0;
}