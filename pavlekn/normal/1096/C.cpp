#include <bits/stdc++.h>

using namespace std;

#define int long long

int mod = 998244353;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int iii = 0; iii < t; ++iii)
    {
        int n;
        cin >> n;
        for (int i = 3; i <= 10000; ++i)
        {
            if ((i * n) % 180 == 0 && (i * n) / 180 <= i - 2)
            {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}