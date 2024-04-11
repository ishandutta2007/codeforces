#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    if (n == 3)
    {
        cout << "2 7 42";
        return 0;
    }
    for (ll y = n + 1; y < 2 * n; y++)
    {
        ll l = 1, r = 1e9;
        while (r - l > 1)
        {
            ll med = (r + l) / 2;
            if (y * med < (y + med) * n)
                l = med;
            else
                r = med;
        }
        if (y * r == (y + r) * n)
        {
            cout << n << " " << y << " " << r;
            return 0;
        }
    }
    cout << -1;
    return 0;
}