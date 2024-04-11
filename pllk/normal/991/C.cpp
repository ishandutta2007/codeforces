#include <iostream>

using namespace std;

typedef long long ll;

ll n;

bool ok(ll k) {
    ll x = n;
    ll a = 0, b = 0;
    while (x > 0) {
        ll u = min(x,k);
        a += u;
        x -= u;
        b += x/10;
        x -= x/10;
    }
    return a*2 >= n;
}

int main() {
    cin >> n;
    ll k = 0;
    for (ll b = n; b >= 1; b /= 2) {
        while (!ok(k+b)) k += b;
    }
    cout << k+1 << "\n";
}