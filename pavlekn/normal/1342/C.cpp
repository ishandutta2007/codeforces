#include <bits/stdc++.h>

using namespace std;

#define int long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int a, b;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int cnt(int r)
{
    int t = (a / gcd(a, b)) * b;
    int c = r / t;
    int s = r % t;
    int ans = c * b;
    ans += min(s, b);
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_)
    {
        cin >> a >> b;
        if (a > b)
        {
            swap(a, b);
        }
        int q;
        cin >> q;
        for (int i = 0; i < q; ++i)
        {
            int l, r;
            cin >> l >> r;
            ++r;
            cout << (r - l) - cnt(r) + cnt(l) << endl;
        }
    }
    return 0;
}