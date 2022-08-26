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
const int maxN = 2e4 + 5;
const int LG = 20;

void solve() {
    int n;
    cin >> n;
    int t = n / 2;
    vl a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) a[i] *= 1000;
    rep(i, n) cin >> b[i];
    vi ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](const int &i, const int &j) {
        return make_pair(a[i], b[i]) < make_pair(a[j], b[j]);
    });
    auto check = [&](ll x) {
        vector<ll> val(n);
        rep(i, n) val[i] = x * b[ord[i]] - a[ord[i]];
        vector<ll> dp(n + 1, -INF);
        dp[0] = 0;
        for(int i = n - 1, j = n - 1; i >= 0; i = j) {
            while(j >= 0 && a[ord[i]] == a[ord[j]]) j--;
            vector<ll> dp2(n + 1, -INF);
            for(int k = i; k >= j; --k) {
                int us = 0, add = 0;
                ll sum = 0;
                for(int e = j + 1; e <= i; ++e) {
                    if (e > k) {
                        sum += val[e];
                        add++;
                    } else {
                        us++;
                    }
                }
                for(int was = us; was <= n; ++was) {
                    if (dp[was] == -INF) continue;
                    dp2[was - us + add] = max(dp2[was - us + add], dp[was] + sum);
                }
            }
            swap(dp, dp2);
        }
        return *max_element(all(dp)) >= 0;
    };

    ll Lb = 0;
    ll Rb = accumulate(all(a), 0ll) + 1;
    while (Rb - Lb > 1) {
        ll mid = (Rb + Lb) / 2;
        if (check(mid)) {
            Rb = mid;
        } else {
            Lb = mid;
        }
    }
    cout << Rb << '\n';
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