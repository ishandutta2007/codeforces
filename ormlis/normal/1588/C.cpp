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

const int INFi = 2e9;
const ll INF = 2e18;
const int maxN = 3e5;

int a[maxN];
ll pref[maxN];
int n;
ll ans = 0;

void solve(int l, int r) {
    if (l + 1 == r) return;
    int mid = (l + r) / 2;
    solve(l, mid);
    solve(mid, r);
    {
        map<ll, int> cnt;
        {
            ll L = -INF;
            ll R = INF;
            for (int i = mid - 1; i >= l; --i) {
                if (L <= pref[i] && pref[i] <= R) {
                    cnt[pref[i]]++;
                }
                if (i & 1) {
                    R = min(R, pref[i]);
                } else {
                    // pref[i] - pref[j] <= 0
                    L = max(L, pref[i]);
                }
            }
        }
        ll L = -INF;
        ll R = INF;
        for (int i = mid; i < r; ++i) {
            if (i & 1) {
                R = min(R, pref[i]);
            } else {
                L = max(L, pref[i]);
            }
            if (L <= pref[i] && pref[i] <= R) ans += cnt[pref[i]];
        }
    }
}

void solve() {
    cin >> n;
    ans = 0;
    rep(i, n) cin >> a[i];
    pref[0] = 0;
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1];
        if (i & 1) pref[i] += a[i - 1];
        else pref[i] -= a[i - 1];
    }
    solve(0, n + 1);
    cout << ans << '\n';
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