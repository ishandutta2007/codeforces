#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long

ll n, m, k;

ll laske(ll x) {
    ll t = 0;
    for (int i = 1; i <= n; i++) {
        ll u = min(i*m, x);
        t += u/i;
    }
    return t;
}

int main() {
    cin >> n >> m >> k;
    ll r = 0;
    for (ll b = n*m; b >= 1; b /= 2) {
        while (r+b <= n*m && laske(r+b) < k) r += b; 
    }
    cout << r+1 << "\n";
}