#include<bits/stdc++.h>

using namespace std;

#define int long long

int mod = 998244353;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a;
    int n, m;
    cin >> n >> m;
    int ans = 1;
    for (int i = 0; i < n + m; ++i)
    {
        ans *= 2;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}