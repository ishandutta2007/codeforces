#include <iostream>

using namespace std;
typedef long long ll;

int cnt1, cnt2, x, y;

bool ok(ll lim) {
    ll both = lim / (x * y);
    ll tox = max(cnt1 - (lim / y - both), 0LL);
    ll toy = max(cnt2 - (lim / x - both), 0LL);
    return (lim - lim / x - lim / y + both >= tox + toy);
}

int main() {
    cin >> cnt1 >> cnt2 >> x >> y;
    ll l = 0, r = 1e18;
    while (r - l > 1) {
        ll m = (l + r) / 2;
        if (ok(m)) r = m; else l = m;
    }
    cout << r << "\n";
    return 0;
}