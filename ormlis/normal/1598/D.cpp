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
#define f0r(a, b) for (int i = (a); i < (b); ++i)
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


void solve() {
    int n;
    cin >> n;
    vvi g1(n), g2(n);
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g1[a].push_back(b);
        g2[b].push_back(a);
    }
    ll result = 0;
    rep(i, n) {
        for (auto &j : g1[i]) {
            ll k = n + 1 - (int)g1[i].size() - (int)g2[j].size();
            result += k * (k - 1) / 2;
        }
    }
    range(_, 2) {
        swap(g1, g2);
        range(i, n) {
            ll sumall = 0;
            for (auto &j : g1[i]) {
                sumall += (int) g2[j].size();
            }
            ll cur = 0;
            for (auto &j : g1[i]) {
                cur += (1ll * n - sz(g1[i]) - sz(g2[j]) + 2) * 1ll * sz(g1[i]) - sumall;
                cur -= n - sz(g1[i]) - sz(g2[j]) - sz(g2[j]) + 2;
            }
            cur /= 2;
            result -= cur;
        }
    }
    result /= 3;
    ll ans = 0;
    range(_, 2) {
        swap(g1, g2);
        ll cur = 1ll * n * (n - 1) * (n - 2) / 6;
        range(i, n) {
            ll k = sz(g1[i]);
            cur -= 1ll * k * (k - 1) * (k - 2) / 6;
            cur -= 1ll * k * (k - 1) / 2 * (n - k);
        }
        ans += cur;
    }
    ans -= result;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}