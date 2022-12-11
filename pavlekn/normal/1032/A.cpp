#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

const int MAXN = 2e3 + 7;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); srand(clock());
    int n, k;
    cin >> n >> k;
    vector<int> count(100);
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        count[x - 1]++;
    }
    int c = 0;
    int mx = 0;
    for (int i = 0; i < 100; ++i)
    {
        if (count[i] != 0)
        {
            ++c;
            mx = max(mx, (count[i]) + (k - (count[i] % k)) % k);
        }
    }
    cout << c * mx - n << endl;
    return 0;
}