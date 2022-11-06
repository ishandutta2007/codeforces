#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) (1e9 + 1e6 + 123);
const ll LINF = (ll) (1e18 + 1e9 + 123);

bool mini(auto& x, const auto& y) {
    if (y < x) {
        x = y;
        return true;
    }
    return false;
}

bool maxi(auto& x, const auto& y) {
    if (x < y) {
        x = y;
        return true;
    }
    return false;
}

void run();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    run();
    return 0;
}

bool ask(ll l, ll r) {
    cout << l << " " << r << endl;
    string res;
    cin >> res;
    bool ok = (res == "Yes");
    if (l == r && ok) {
        exit(0);
    }
    return ok;
}

void run() {
    mt19937 rnd(31);
    ll n;
    int k;
    ll p;
    cin >> n >> k;
    ll l = 1, r = n;
    while (true) {
        while (r - l + 1 > 4 * k) {
            ll m = (l + r) / 2;
            if (ask(l, m)) {
                r = m;
            } else {
                l = m + 1;
            }
            l = max(1LL, l - k);
            r = min(n, r + k);
        }
        ll x = rnd() % (r - l + 1) + l;
        ask(x, x);
        l = max(1LL, l - k);
        r = min(n, r + k);
    }
}