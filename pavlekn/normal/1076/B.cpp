#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); srand(clock());
    int n;
    cin >> n;
    int ans = n;
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            ans = min(ans, i);
        }
    }
    if (ans == 2)
    {
        cout << n / 2 << endl;
    }
    else
    {
        cout << (n - ans) / 2 + 1 << endl;
    }
}