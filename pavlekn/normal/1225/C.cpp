#include<bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e6 + 7;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, p;
    cin >> n >> p;
    for (int i = 1; i < 50; ++i)
    {
        if (n - p * i >= i && __builtin_popcount(n - p * i) <= i)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}