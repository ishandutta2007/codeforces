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
const int maxN = 1e5 + 30;
const int LG = 19;

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

int pw2[maxN];

struct Segment {
    int l, r;
    ll sum;
};

void solve() {
    pw2[0] = 1;
    for (int i = 1; i < maxN; ++i) pw2[i] = mul(pw2[i - 1], 2);
    int n, q;
    cin >> n >> q;
    vi a(n);
    vi b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) b[i] = (a[i] + md) % md;
    auto c = b;
    for (int i = n - 2; i >= 0; --i) c[i] = add(c[i], mul(c[i + 1], 2));
    auto get = [&](int l, int r) {
        int res = c[l];
        if (r + 1 != n) res = sub(res, mul(c[r + 1], pw2[r + 1 - l]));
        return res;
    };
    vector<int> l(q), r(q);
    vvi to(n);
    rep(i, q) {
        cin >> l[i] >> r[i];
        l[i]--;
        r[i]--;
        to[r[i]].push_back(i);
    }
    vector<Segment> segs;
    vector<int> pref;
    pref.push_back(0);
    vi res(q);
    rep(i, n) {
        Segment s;
        s.l = i;
        s.r = i;
        s.sum = a[i];
        while (!segs.empty() && s.sum > 0) {
            ll len = segs.back().r - segs.back().l + 1;
            if (s.sum == INFi) {
                s.l = segs.back().l;
                segs.pop_back();
                pref.pop_back();
                continue;
            }
            ll add = s.sum;
            s.sum += segs.back().sum;
            rep(_, len) {
                if (s.sum >= INFi) break;
                s.sum += add;
                add *= 2;
            }
            s.sum = min(s.sum, (ll) INFi);
            s.l = segs.back().l;
            segs.pop_back();
            pref.pop_back();
        }
        int pref_sum = pref.back();
        pref.push_back(add(pref_sum, get(s.l, s.r)));
        segs.push_back(s);
        for (auto &j : to[i]) {
            int L = l[j];
            int m;
            {
                int lb = 0;
                int rb = segs.size();
                while (rb - lb > 1) {
                    int mid = (rb + lb) / 2;
                    if (segs[mid].l > L) rb = mid;
                    else lb = mid;
                }
                m = lb;
            }
            int ans = mul(2, sub(pref.back(), pref[m + 1]));
            ans = add(ans, get(L, segs[m].r));
            res[j] = ans;
        }
    }
    rep(i, q) cout << res[i] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(20 - 7) << fixed;
    int t = 1;
    // cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}