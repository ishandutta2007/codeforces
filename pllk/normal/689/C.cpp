#include <iostream>

using namespace std;

typedef long long ll;

ll calc(ll n) {
    ll x = 0;
    for (ll u = 2; ; u++) {
        if (u*u*u > n) return x;
        ll a = 1;
        ll r = n/(u*u*u)+1;
        for (ll b = r; b >= 1; b /= 2) {
            while ((a+b)*u*u*u <= n) a += b;
        }
        x += a;
    }
}

int main() {
    ll m;
    cin >> m;
    ll u = 0;
    for (ll b = 100000000000000LL; b >= 1; b /= 2) {
        while (calc(u+b) < m) u += b;
    }
    u++;
    if (calc(u) == m) cout << u << "\n";
    else cout << "-1\n";
}