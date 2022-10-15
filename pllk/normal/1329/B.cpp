#include <iostream>

using namespace std;

typedef long long ll;

ll calc(ll d, ll m) {
    ll u = 0;
    ll b = 1;
    while (2*b-1 < d) b *= 2;
    ll e = d-(b-1);
    u += e;
    ll f = e+1;
    for (; b >= 2; b /= 2) {
        u += (b/2)*f;
        u %= m;
        f *= (b/2)+1;
        f %= m;
    }
    return u%m;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll d, m;
        cin >> d >> m;
        cout << calc(d,m) << "\n";
    }
    calc(14,1000000000);
}