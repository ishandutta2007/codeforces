#include <iostream>

using namespace std;

typedef long long ll;

int n;
int a[101010];
ll d[101010];
ll f;
ll s1, s2;

bool ok(ll x) {
    ll a1 = f-x;
    ll a2 = x;
    return a1+s1 <= x;
}

ll calc() {
    ll k = -1e18;
    for (ll b = 1e16; b >= 1; b /= 2) {
        while (!ok(k+b)) k += b;
    }
    return k+1;
}

void add(ll x) {
    if (x >= 0) s1 += x;
    else s2 += -x;
}

void rem(ll x) {
    if (x >= 0) s1 -= x;
    else s2 = x;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    f = a[1];
    for (int i = 1; i <= n-1; i++) {
        d[i] = a[i+1]-a[i];
        add(d[i]);
    }
    cout << calc() << "\n";
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        if (l == 1) f += x;
        if (l != 1) {
            rem(d[l-1]);
            d[l-1] += x;
            add(d[l-1]);
        }
        if (r != n) {
            rem(d[r]);
            d[r] -= x;
            add(d[r]);
        }
        cout << calc() << "\n";
    }
}