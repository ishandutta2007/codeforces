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
const int maxN = 2e5;
const int K = 350;

pi val[maxN];
ll pref[maxN];
int n;

void rebuild(int b) {
    int l = b * K;
    int r = min(l + K, n);
    sort(val + l, val + r);
    pref[l] = val[l].second - val[l].first;
    for (int i = l + 1; i < r; ++i) pref[i] = pref[i - 1] + val[i].second - val[i].first;
}

void upd(int i, int x) {
    int b = i / K;
    for (int j = b * K;; ++j) {
        assert(j < n && j < (b + 1) * K);
        if (val[j].second == i) {
            val[j].first = x;
            break;
        }
    }
    rebuild(b);
}

ll get(int l, int r) {
    int lq = l / K;
    int rq = (r - 1) / K;
    ll ans = 0;
    assert(lq <= rq);
    if (lq == rq) {
        for (int i = lq * K; i < n && i < (lq + 1) * K; ++i) {
            if (val[i].second < r && val[i].first >= l) {
                ans += val[i].second - val[i].first;
            }
        }
        return ans;
    }
    for (int i = lq * K; i < n && i < (lq + 1) * K; ++i) {
        if (val[i].second < r && val[i].first >= l) {
            ans += val[i].second - val[i].first;
        }
    }
    for (int i = rq * K; i < n && i < (rq + 1) * K; ++i) {
        if (val[i].second < r && val[i].first >= l) {
            ans += val[i].second - val[i].first;
        }
    }
    for (int i = lq + 1; i < rq; ++i) {
        int L = i * K;
        int R = min(L + K, n);
        int j = lower_bound(val + L, val + R, pair<int, int>{l, -1}) - val;
        ans += pref[R - 1];
        if (j != L) ans -= pref[j - 1];
    }
    return ans;
}


void solve() {
    int m;
    cin >> n >> m;
    vi a(n);
    rep(i, n) cin >> a[i];
    rep(i, n) a[i]--;
    vector<set<int>> to(n);
    rep(i, n) {
        to[a[i]].insert(i);
    }
    rep(i, n) {
        auto it = to[a[i]].find(i);
        if (it == to[a[i]].begin()) {
            val[i] = {-1, i};
        } else {
            val[i] = {*prev(it), i};
        }
    }
    rep(i, (n - 1) / K + 1) rebuild(i);
    rep(_, m) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int p, x;
            cin >> p >> x;
            p--;
            x--;
            if (a[p] == x) continue;
            to[a[p]].erase(p);
            {
                auto it = to[a[p]].upper_bound(p);
                if (it != to[a[p]].end()) {
                    int must = -1;
                    if (it != to[a[p]].begin()) must = *prev(it);
                    upd(*it, must);
                }
            }
            a[p] = x;
            {
                auto it = to[x].lower_bound(p);
                if (it != to[x].end()) {
                    upd(*it, p);
                }
                if (it != to[x].begin()) {
                    upd(p, *prev(it));
                } else {
                    upd(p, -1);
                }
            }
            to[x].insert(p);
        } else {
            int l, r; cin >> l >> r;
            l--;
            cout << get(l, r) << '\n';
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}