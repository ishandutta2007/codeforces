#include <iostream>

using namespace std;

typedef long long ll;

int n;
ll x;

void lol() {
    cin >> n >> x;
    bool ok = 0;
    ll s = 0;
    for (int i = 1; i <= n; i++) {
        ll a;
        cin >> a;
        if (a == x) ok = 1;
        if (a > s) s = a;
    }
    if (ok) {
        cout << "1\n";
        return;
    }
    ll u = x/s;
    if (x%s != 0) u++;
    if (u == 1) u = 2;
    cout << u << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) lol();
}