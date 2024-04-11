#include <iostream>

using namespace std;

typedef long long ll;

ll n, k;

bool ok1(ll x) {
    return k-x <= n;
}

bool ok2(ll x) {
    return x <= n && x < k-x;
}

int main() {
    cin >> n >> k;
    ll x = 0;
    ll u = max(n,k);
    for (ll b = u; b >= 1; b /= 2) {
        while (!ok1(x+b)) x += b;
    }
    if (!ok2(x+1)) {
        cout << "0\n";
        return 0;
    }
    ll x1 = x;
    for (ll b = u; b >= 1; b /= 2) {
        while (ok2(x+b)) x += b;
    }
    cout << x-x1 << "\n";
}