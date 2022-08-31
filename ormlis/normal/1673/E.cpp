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

const int INFi = 1e9 + 10;
const ll INF = 2e18;
const int maxN = (1 << 20) + 1;
const int maxP = 1000;
const int LG = 30;

ll was[maxN];

ll check(int x) {
    if (was[x]) return was[x];
    ll ans = 0;
    for (int i = 2; i <= x; i *= 2) {
        ans += x / i;
    }
    return was[x] = ans;
}

void solve() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    vi b(n);
    rep(i, n) cin >> b[i];
    int L = 25;
    vector<ar<int, 3>> cnt(L, ar<int, 3>{0, 0, 0});
    rep(i, L) {
        int ost = n - i;
        rep(j, 3) {
            int need = k - j;
            for (int us = max(0, need); us <= ost; ++us) {
                // C(ost, us)
                // ost! / us! / (ost - us)!
                cnt[i][j] ^= int((check(ost) - check(us) - check(ost - us)) == 0);
            }
        }
    }
    const int N = 1 << 20;
    vi ans(N);
    for (int l = 0; l < n; ++l) {
        int r = l;
        ll cur = b[l];
        while (cur < N) {
            int ost = max(0, l - 1) + max(0, n - 2 - r);
            int us = int(l != 0) + int(r != n - 1);
            ans[cur] ^= cnt[n - ost][us];
            if (r == n - 1) break;
            r++;
            if (b[r] >= 20) break;
            cur *= (1ll << b[r]);
        }
    }
    bool was = false;
    for (int i = N - 1; i >= 0; --i) {
        if (i == 0 || ans[i]) was = true;
        if (was) cout << ans[i];
    }
    cout << '\n';
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}