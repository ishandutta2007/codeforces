#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const long long INF = (long long) 1e12 + 100;

void run();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    run();
    return 0;
}

bool check(ll x) {
    for (ll i = 2; i * i <= x; i++) {
        if (i < x && x % i == 0) {
            return false;
        }
    }
    return true;
}

void run() {
    int t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        bool ok;
        if ((a - b) == 1) {
            ok = check(a + b);
        } else {
            ok = false;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}