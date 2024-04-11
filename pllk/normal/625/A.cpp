#include <iostream>

using namespace std;

typedef long long ll;

ll n;
ll a, b, c;

bool ok(ll x) {
    ll u = n-x*(b-c);
    if (u < 0) return false;
    if (u-c < 0) return false;
    return true;
}

int main() {
    cin >> n;
    cin >> a >> b >> c;
    if (a < b-c) {
        cout << n/a << "\n";
        return 0;
    }
    ll r = 0;
    for (ll x = n/(b-c); x >= 1; x /= 2) {
        while (ok(r+x)) r += x;
    }
    n -= r*(b-c);
    r += n/a;
    cout << r << "\n";
}