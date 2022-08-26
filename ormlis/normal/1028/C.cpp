#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
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

const int INFi = 2e9;
const ll INF = 2e18;
const int maxN = 1e5 + 100;
const int LG = 20;

void solve() {
    int n; cin >> n;
    vector<ar<int, 4>> a(n);
    rep(i, n) rep(j, 4) cin >> a[i][j];
    vector<ar<int, 4>> pref(n + 1);
    pref[0] = {-INFi, -INFi, INFi, INFi};
    auto intersect = [&] (ar<int, 4> &r1, ar<int, 4> &r2) {
        return ar<int, 4> {max(r1[0], r2[0]), max(r1[1], r2[1]), min(r1[2], r2[2]), min(r1[3], r2[3])};
    };
    rep(i, n) {
        pref[i + 1] = intersect(pref[i], a[i]);
    }
    ar<int, 4> suf = pref[0];
    for(int i = n - 1; i >= 0; --i) {
        auto cur = intersect(pref[i], suf);
        if (cur[0] <= cur[2] && cur[1] <= cur[3]) {
            cout << cur[0] << ' ' << cur[1] << '\n';
            return;
        }
        suf = intersect(suf, a[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}