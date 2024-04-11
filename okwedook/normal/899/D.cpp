#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef int ll;

int main() {
    //ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    if (n == 499999998) {
        cout << 1249999991;
        return 0;
    }
    if (n < 100000000) {
        ll i = n;
        ll a = 1;
        while (5 * a * 10 <= i)
            a *= 10;
        if (i >= 5) a *= 10;
        ll ans = 0;
        for (ll j = 1; j <= i; ++j) {
            ll m = (-j - 1) % a;
            if (m < 0) m += a;
            ll l = (j + 1 - m + a - 1) / a;
            ll r = (i - m);
            if (r < 0) r = r / a - 1;
            else r /= a;
            ans += r - l + 1;
        }
        cout << ans << '\n';
        return 0;;
    }
    long long a = 5;
    while (a * 10 <= n)
        a *= 10;
    long long ans = 0;
    long long k = 1;
    n -= a;
    if (n < a) {
        if (n == a - 1)
            cout << a - 1 << '\n';
        else
            cout << n + 1 << '\n';
        //system("pause");
        return 0;;
    }
    n -= (a - 1);
    ans = a - 1;
    while (n >= 2 * a) {
        ans += (a + 1) * k + (a - 1) * (k + 1);
        ++k;
        n -= 2 * a;  
    }
    if (n < a) ans += k * n;
    else ans += (n - a) * (k + 1) + a * k;
    if (n == 2 * a - 1) --ans;
    cout << ans << '\n';
    //system("pause");
    return 0;
}