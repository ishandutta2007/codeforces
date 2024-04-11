#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
#define rep1n(i, n) for(int i = 1; i <= (n); ++i)
#define repr(i, n) for(int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for(auto &x : a)
#define ar array
#define vec vector
#define f0r(a, b) for(int i = (a); i < (b); ++i)
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
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

const int md = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<ll> bad;
    map<ll, int> cnt;
    map<ll, int> sq3;
    for (int j = 2; j <= 2e6; ++j) {
        ll t = 1;
        range(_, 3) t *= j;
        sq3[t] = j;
    }
    rep(i, n) {
        ll x;
        cin >> x;
        if (x == 1) continue;
        if (sq3.count(x)) {
            cnt[sq3[x]] += 3;
            continue;
        }
        ll sq = sqrtl(x);
        while (sq * sq < x) sq++;
        while (sq * sq > x) sq--;
        if (sq * sq == x) {
            ll s = sqrtl(sq);
            while (s * s < sq) s++;
            while (s * s > sq) s--;
            if (s * s == sq) {
                cnt[s] += 4;
            } else {
                cnt[sq] += 2;
            }
        } else {
            bad.push_back(x);
        }
    }
    ll ans = 1;
    map<ll, int> kek;
    for (auto x : bad) {
        ll g = 1;
        for (auto y : bad) {
            g = __gcd(x, y);
            if (g == 1 || g == x) continue;
            break;
        }
        if (g == 1 || g == x) {
            for (auto[p, t] : cnt) {
                if (x % p == 0) {
                    g = p;
                    break;
                }
            }
        }
        if (g != 1 && g != x) {
            while (x % g == 0) {
                x /= g;
                cnt[g]++;
            }
            if (x != 1) {
                cnt[x]++;
            }
        } else {
            kek[x]++;
        }
    }
    for (auto &[p, t] : cnt) ans = (ans * (t + 1)) % md;
    for (auto &[p, t] : kek) ans = (ans * (t + 1)) % md;
    for (auto &[p, t] : kek) ans = (ans * (t + 1)) % md;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20-7) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}