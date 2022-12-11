#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    int x, y, k;
    for (int i = 0; i < q; ++i)
    {
        cin >> x >> y >> k;
        if (max(abs(x), abs(y)) > k)
        {
            cout << -1 << endl;
        }
        else
        {
            int res;
            if (abs(x) % 2 == abs(y) % 2)
            {
                res = k;
                if (x % 2 != k % 2)
                {
                    res -= 2;
                }
            }
            else
            {
                res = k - 1;
            }
            cout << res << endl;
        }
    }
}