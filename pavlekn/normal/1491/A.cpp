#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e6 + 7;

int a[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        cnt += a[i];
    }
    for (int _ = 0; _ < q; ++_)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int pos;
            cin >> pos;
            --pos;
            cnt -= a[pos];
            a[pos] = 1 - a[pos];
            cnt += a[pos];
        }
        if (t == 2)
        {
            int x;
            cin >> x;
            if (cnt >= x)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
    }
    return 0;
}