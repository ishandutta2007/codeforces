#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ll k2, k3, k5, k6;
    cin >> k2 >> k3 >> k5 >> k6;
    ll k = min(min(k2, k5), k6);
    ll ans = k * 256;
    k2 -= k;
    k5 -= k;
    k6 -= k;
    k = min(k2, k3);
    cout << ans + k * 32;
    return 0;
}