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
const int maxN = 1e6 + 20;
const int LG = 100;
const int md = 998244353; //1e9 + 7, 1e9 + 9

const long double sqrt3 = sqrtl(3);
const long double PI = atan2(0, -1);

ld dist(pair<ld, ld> a, pair<ld, ld> b) {
    return sqrtl((a.first - b.first) * (a.first - b.first) +
                 (a.second - b.second) * (a.second - b.second));
}

long double
f(long double x1, long double y1, long double x2, long double y2, long double x3, long double y3) {
    vector<pair<ld, ld>> wtf = {
            {x1, y1},
            {x2, y2},
            {x3, y3}
    };
    rep(i, 3) {
        int j = (i + 1) % 3;
        int e = (i + 2) % 3;
        ld angle = atan2(wtf[j].second - wtf[i].second, wtf[j].first - wtf[i].first) -
                   atan2(wtf[e].second - wtf[i].second, wtf[e].first - wtf[i].first);
        while (angle < 0) angle += 2 * PI;
        while (angle >= 2 * PI) angle -= 2 * PI;
        if (angle > PI) angle = 2 * PI - angle;
        if (angle * 3 > PI * 2) {
            return dist(wtf[i], wtf[j]) + dist(wtf[i], wtf[e]);
        }
    }
    long double ans = x1 * x1 + y1 * y1 + x2 * x2 + y2 * y2 + x3 * x3 + y3 * y3;
    ans -= x1 * x2 + x2 * x3 + x3 * x1 + y1 * y2 + y2 * y3 + y3 * y1;
    ans += sqrt3 * abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
    return sqrtl(ans);
}

void solve() {
    int n = 3;
    vector<pair<ld, ld>> pts(n);
    rep(i, n) cin >> pts[i].first >> pts[i].second;
    vector<pair<int, int>> kek = {
            {0, 1},
            {0, 2},
            {1, 2}
    };
    auto get = [&](ld x, ld y) {
        ld res = 0;
        for (auto &[a, b] : kek) {
            res = max(res, f(x, y, pts[a].first, pts[a].second, pts[b].first, pts[b].second));
        }
        /*if (res < 25) {
            cout << x << ' ' << y << '\n';
        }*/
        return res;
    };
    auto check = [&](ld x) {
        ld L2 = -1e6;
        ld R2 = 1e6;
        rep(__, 300) {
            ld midR = (L2 + R2 * 2) / 3;
            ld midL = (L2 * 2 + R2) / 3;
            ld v1 = get(x, midL);
            ld v2 = get(x, midR);
            if (v1 > v2) {
                L2 = midL;
            } else {
                R2 = midR;
            }
        }
        return min(get(x, L2), get(x, R2));
    };

    ld L1 = -1e6;
    ld R1 = 1e6;
    rep(_, 300) {
        ld midR = (L1 + R1 * 2) / 3;
        ld midL = (L1 * 2 + R1) / 3;
        ld v1 = check(midL);
        ld v2 = check(midR);
        if (v1 > v2) {
            L1 = midL;
        } else {
            R1 = midR;
        }
    }
    cout << min(check(L1), check(R1));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int t = 1;
    // cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}