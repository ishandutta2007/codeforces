#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
#define vec vector

using namespace std;

using ll = long long;
using ld = double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

int Bit(int mask, int b) { return (mask >> b) & 1; }

template<class T>
bool ckmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool ckmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    vl a(n);
    rep(i, n) cin >> a[i];
    ar<ll, 2> g = {0, 0};
    rep(i, n) g[i % 2] = __gcd(g[i % 2], a[i]);
    bool ok1 = true;
    {
        ll d = g[0];
        for (int i = 1; i < n; i += 2) {
            if (a[i] % d == 0) {
                ok1 = false;
            }
        }
    }
    bool ok2 = true;
    {
        ll d = g[1];
        for (int i = 0; i < n; i += 2) {
            if (a[i] % d == 0) {
                ok2 = false;
            }
        }
    }
    if (ok1) {
        cout << g[0] << '\n';
    } else if (ok2) {
        cout << g[1] << '\n';
    } else {
        cout << "0\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    cin >> t;
    rep(_, t) {
        solve();
    }
    return 0;
}