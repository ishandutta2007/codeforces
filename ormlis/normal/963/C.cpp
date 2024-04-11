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
const int maxN = 2e5 + 5;
const int LG = 20;

void solve() {
    int n;
    cin >> n;
    vector<ar<ll, 3>> edges(n);
    vl w, h;
    rep(i, n) {
        rep(j, 3) cin >> edges[i][j];
        w.push_back(edges[i][0]);
        h.push_back(edges[i][1]);
    }
    sort(all(w));
    w.resize(unique(all(w)) - w.begin());
    sort(all(h));
    h.resize(unique(all(h)) - h.begin());
    if (1ll * (int) w.size() * (int) h.size() != n) {
        cout << "0\n";
        return;
    }
    rep(i, n) {
        edges[i][0] = lower_bound(all(w), edges[i][0]) - w.begin();
        edges[i][1] = lower_bound(all(h), edges[i][1]) - h.begin();
    }
    vl mnW(w.size(), 1), mxW(w.size(), 0);
    vl mnH(h.size(), 1), mxH(h.size(), 0);
    for (auto &[a, b, c] : edges) {
        mxW[a] = __gcd(mxW[a], c);
        mxH[b] = __gcd(mxH[b], c);
    }
    ll ans = 0;
    bool ok = true;
    while (ok) {
        ok = false;
        for (auto &[a, b, c] : edges) {
            if (!ok) {
                if (mxW[a] % (c / mnH[b]) != 0) ok = true;
                else if (mxH[b] % (c / mnW[a]) != 0) ok = true;
            }
            mxW[a] = __gcd(mxW[a], c / mnH[b]);
            mxH[b] = __gcd(mxH[b], c / mnW[a]);
            {
                ll to = c / mxH[b];
                to /= __gcd(mnW[a], to);
                if (to != 1) {
                    if ((mxW[a] / mnW[a]) % to != 0) {
                        cout << "0\n";
                        return;
                    }
                    mnW[a] *= to;
                    ok = true;
                }
            }
            {
                ll to = c / mxW[a];
                to /= __gcd(mnH[b], to);
                if (to != 1) {
                    if ((mxH[b] / mnH[b]) % to != 0) {
                        cout << "0\n";
                        return;
                    }
                    mnH[b] *= to;
                    ok = true;
                }
            }
        }
    }
    ll to = mxW[0] / mnW[0];
    ll res = 0;
    for (ll i = 1; i * i <= to; ++i) {
        if (to % i == 0) {
            res += 2;
            if (i * i == to) res--;
        }
    }
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(20 - 7) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}