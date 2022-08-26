#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll INF = 2e18;
const int INFi = 2e9 + 5;
const int maxN = 1e5 + 1;
const int md = 1e9 + 7;

inline int add(const int &a, const int &b) {
    return a + b >= md ? a + b - md : a + b;
}

inline int sub(const int &a, const int &b) {
    return a - b < 0 ? a - b + md : a - b;
}

inline int mul(const int &a, const int &b) {
    return (1ll * a * b) % md;
}

int binpow(int a, int b) {
    if (b <= 0) return 1;
    if (b % 2) return mul(a, binpow(a, b - 1));
    int m = binpow(a, b / 2);
    return mul(m, m);
}

int rev(int a) {
    return binpow(a, md - 2);
}

void solve() {
    int n; cin >> n;
    vector<int> c(n);
    range(i, n) cin >> c[i];
    vector<ll> b(n);
    range(i, n - 1) cin >> b[i + 1];
    {
        ll s = 0;
        range(i, n) {
            s += b[i];
            b[i] = s;
            if (i) b[i] += b[i - 1];
        }
    }
    int q; cin >> q;
    const int maxK = 101;
    auto calc = [&] (int x) {
        vector<int> dp(maxK * maxK);
        dp[0] = 1;
        ll need = 0;
        range(i, n) {
            need += x;
            ll cur = need + b[i];
            vector<int> newdp(maxK * maxK);
            if (cur < maxK * maxK) {
                int s = 0;
                for(int j = max(cur - c[i] - 1, 0ll); j < cur; ++j) {
                    s = add(s, dp[j]);
                }
                for (int sum = max(cur, 0ll); sum < maxK * maxK; ++sum) {
                    s = add(s, dp[sum]);
                    if (sum - c[i] - 1 >= 0) s = sub(s, dp[sum - c[i] - 1]);
                    newdp[sum] = s;
                }
            }
            swap(dp, newdp);
        }
        int ans = 0;
        range(i, maxK * maxK) ans = add(ans, dp[i]);
        return ans;
    };
    int mn = 1e5, mx = 1e5;
    auto upd = [&] (ll x) {
        x = min(x, (ll)1e5);
        mn = min(mn, (int)x - 1);
    };
    range(i, n) {
        upd((-b[i]) / (i + 1));
    }
    ll s = 0;
    range(i, n) {
        s += c[i];
        ll w = s - b[i];
        w /= (i + 1);
        w++;
        if (w < 1e5) {
            if (w < -1e5) w = -1e5;
            mx = min(mx, (int)w);
        }
    }
    map<int, int> res;
    for(int i = mn; i <= mx; ++i) {
        res[i] = calc(i);
    }
    range(_, q) {
        int x; cin >> x;
        if (x < mn) {
            cout << res[mn] << '\n';
        } else if (x > mx) {
            cout << res[mx] << '\n';
        } else {
            cout << res[x] << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}