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
const int maxN = 6e6 + 100;
const int LG = 20;

void solve() {
    int n, m; cin >> n >> m;
    vi a(n);
    rep(i, n) cin >> a[i];
    vvi b(m);
    vl s(m);
    vi cnt(m);
    vvi ans(m);
    rep(i, m) {
        int k; cin >> k;
        b[i].resize(k);
        ans[i].resize(k, 0);
        rep(j, k) cin >> b[i][j];
        cnt[i] = k;
        s[i] = accumulate(all(b[i]), 0ll);
    }
    sort(rall(a));
    a.resize(m);
    reverse(all(a));
    vi ord(m);
    iota(all(ord), 0);
    sort(all(ord), [&] (const int &i, const int &j) {
        return 1ll * s[i] * cnt[j] < 1ll * cnt[i] * s[j];
    });
    vi canS(m);
    vi canL(m);
    vi canR(m);
    rep(j, m) {
        int i = ord[j];
        if (s[i] <= 1ll * cnt[i] * a[j]) {
            canS[j] = 1;
        }
        if (j >= 1 && s[i] <= 1ll * cnt[i] * a[j - 1]) {
            canL[j] = 1;
        }
        if (j + 1 < m && s[i] <= 1ll * cnt[i] * a[j + 1]) {
            canR[j] = 1;
        }
    }
    for(int i = 1; i < m; ++i) {
        canS[i] += canS[i - 1];
        canL[i] += canL[i - 1];
        canR[i] += canR[i - 1];
    }
    vi pos(m);
    rep(i, m) pos[ord[i]] = i;
    auto getS = [&] (int l, int r) {
        if (l > r) return 0;
        int res = canS[r];
        if (l != 0) res -= canS[l - 1];
        return res;
    };

    auto getR = [&] (int l, int r) {
        if (l > r) return 0;
        int res = canR[r];
        if (l != 0) res -= canR[l - 1];
        return res;
    };

    auto getL = [&] (int l, int r) {
        if (l > r) return 0;
        int res = canL[r];
        if (l != 0) res -= canL[l - 1];
        return res;
    };
    rep(i, m) {
        int p = pos[i];
        rep(j, cnt[i]) {
            ll s2 = s[i] - b[i][j];
            ll cnt2 = cnt[i] - 1;
            int L = -1, R = m;
            while(R - L > 1) {
                int mid = (L + R) / 2;
                if (1ll * s2 * cnt[ord[mid]] < 1ll * cnt2 * s[ord[mid]]) {
                    R = mid;
                } else {
                    L = mid;
                }
            }
            int p2;
            if (L >= p) {
                p2 = L;
            } else {
                p2 = R;
            }
            int re = 0;
            if (p <= p2) {
                re += getS(0, p - 1);
                re += getS(p2 + 1, m - 1);
                re += getL(p + 1, p2);
                if (s2 <= 1ll * cnt2 * a[p2]) {
                    re++;
                }
            } else {
                re += getS(0, p2 - 1);
                re += getS(p + 1, m - 1);
                re += getR(p2, p - 1);
                if (s2 <= 1ll * cnt2 * a[p2]) {
                    re++;
                }
            }
            if (re != m) continue;
            ans[i][j] = 1;
        }
    }
    rep(i, m) {
        rep(j, cnt[i]) {
            cout << ans[i][j];
        }
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}