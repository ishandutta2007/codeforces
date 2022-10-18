#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define For(i, n) for (int i = 0; i < n; i++)
using namespace std;

vector<ll> a, b, c, d;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    ll x, s;
    cin >> x >> s;
    ll ans = x * n;
    a.resize(m);
    b.resize(m);
    c.resize(k);
    d.resize(k);
    For(i, m)
        cin >> a[i];
    For(i, m)
        cin >> b[i];
    For(i, k)
        cin >> c[i];
    For(i, k)
        cin >> d[i];
    for (int i = 0; i < m; i++)
    {
        int l = -1, r = k;
        while (r - l > 1)
        {
            int med = (r + l) / 2;
            if (d[med] > s - b[i])
                r = med;
            else
                l = med;
        }
        if (l == -1)
        {
            if (b[i] <= s)
                ans = min(ans, a[i] * n);
        }
        else
            ans = min(ans, a[i] * (n - c[l]));
    }
    ll null = 0;
    for (int i = 0; i < k; i++)
        if (d[i] <= s)
            ans = min(ans, x * max(n - c[i], null));
    cout << ans;
    return 0;
}