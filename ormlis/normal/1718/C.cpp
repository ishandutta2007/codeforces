#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using i128 = __int128;
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
const int LG = 20;
const int maxN = 2e5 + 10;

bool is_prime[maxN];

void primes() {
    // fill(is_prime + 2, is_prime + maxN, true);
    for (int i = 2; i < maxN; ++i) {
        if (!is_prime[i]) {
            for (int j = i + i; j < maxN; j += i) {
                is_prime[j] = true;
            }
        }
    }
}

void solve() {
    int n, q; cin >> n >> q;
    vi a(n);
    rep(i, n) cin >> a[i];
    auto b = a;
    vi p(q), x(q);
    rep(i, q) {
        cin >> p[i] >> x[i];
        p[i]--;
        x[i] = x[i] - b[p[i]];
        b[p[i]] += x[i];
    }
    vl ans(q + 1, -1);
    for(int k = 1; k < n; ++k) {
        if (is_prime[n / k]) continue;
        if (n % k != 0) continue;
        vl val(k * 2);
        rep(i, n) val[(i % k) + k] += a[i];
        for(int i = k - 1; i >= 1; --i) val[i] = max(val[i << 1], val[i << 1 | 1]);
        {
            ll res = 0;
            for(int l = k, r = 2 * k; l < r; l >>= 1, r >>= 1) {
                if (l & 1) res = max(res, val[l++]);
                if (r & 1) res = max(res, val[--r]);
            }
            ans[0] = max(ans[0], res * k);
        }
        rep(j, q) {
            int t = p[j] % k;
            for(val[t += k] += x[j]; t > 1; t >>= 1) val[t >> 1] = max(val[t], val[t ^ 1]);
            {
                ll res = 0;
                for(int l = k, r = 2 * k; l < r; l >>= 1, r >>= 1) {
                    if (l & 1) res = max(res, val[l++]);
                    if (r & 1) res = max(res, val[--r]);
                }
                ans[j + 1] = max(ans[j + 1], res * k);
            }
        }
    }
    rep(i, q + 1) cout << ans[i] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    primes();
    //cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}