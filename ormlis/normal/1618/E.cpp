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
    int n; cin >> n;
    vi b(n);
    rep(i, n) cin >> b[i];
    ll sum = accumulate(all(b), 0ll);
    ll need = 1ll * n * (n + 1) / 2;
    if (sum % need) {
        cout << "NO\n";
        return;
    }
    sum /= need;
    vector<ll> a(n);
    rep(i, n) {
        ll x = b[(i + 1) % n] - b[i];
        ll t = sum - x;
        if (t % n || t <= 0) {
            cout << "NO\n";
            return;
        }
        a[(i + 1) % n] = t / n;
    }
    cout << "YES\n";
    rep(i, n) cout << a[i] << ' ';
    cout << '\n';
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