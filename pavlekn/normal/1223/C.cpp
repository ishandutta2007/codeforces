#include<bits/stdc++.h>

using namespace std;

#define int long long

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int q;
    cin >> q;
    for (int _ = 0; _ < q; ++_)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            a[i] /= 100ll;
        }
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        int a1, x;
        cin >> x >> a1;
        int b, y;
        cin >> y >> b;
        if (x < y)
        {
            swap(x, y);
            swap(a1, b);
        }
        int k;
        cin >> k;
        int l = 0ll;
        int r = n + 1ll;
        while (r - l > 1ll)
        {
            int m = (l + r) / 2ll;
            int c1 = m / (a1 * b / gcd(a1, b));
            int c2 = m / a1 - c1;
            int c3 = m / b - c1;
            int cur = 0;
            for (int i = 0; i < c1; ++i)
            {
                cur += a[i] * (x + y);
            }
            for (int i = c1; i < c1 + c2; ++i)
            {
                cur += a[i] * x;
            }
            for (int i = c1 + c2; i < c1 + c2 + c3; ++i)
            {
                cur += a[i] * y;
            }
            if (cur >= k)
            {
                r = m;
            }
            else
            {
                l = m;
            }
        }
        if (r == n + 1ll)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << r << endl;
        }
    }
    return 0;
}