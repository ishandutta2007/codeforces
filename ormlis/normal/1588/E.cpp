#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2")

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
using ld = double;
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

struct pt {
    int x = 0, y = 0;
};

bool operator<(const pt &a, const pt &b) {
    return tie(a.x, a.y) < tie(b.x, b.y);
}

bool operator==(const pt &a, const pt &b) {
    return tie(a.x, a.y) == tie(b.x, b.y);
}

pt operator+(const pt &a, const pt &b) {
    return {a.x + b.x, a.y + b.y};
}

pt operator-(const pt &a, const pt &b) {
    return {a.x - b.x, a.y - b.y};
}

// - 
ll operator*(const pt &a, const pt &b) {
    return 1ll * a.x * b.y -  1ll * a.y * b.x;
}

//
ll operator%(const pt &a, const pt &b) {
    return 1ll * a.x * b.x + 1ll * a.y * b.y;
}

void solve() {
    int n, R; cin >> n >> R;
    vector<pt> pts(n);
    rep(i, n) cin >> pts[i].x >> pts[i].y;
    vector<vector<bool>> good(n, vector<bool> (n, true));
    rep(i, n) good[i][i] = false;
    const ld PI = atan2(0, -1);
    rep(i, n) {
        ld L2 = 0, R2 = 4 * PI;
        vector<pair<ld, int>> to;
        rep(j, n) {
            if (i != j) {
                auto pt = pts[j] - pts[i];
                ld ang = atan2(pt.y, pt.x);
                to.push_back({ang, j});
            }
            ll d = (pts[i] - pts[j])  % (pts[i] - pts[j]);
            if (d <= 1ll * R * R) continue;
            auto pt = pts[j] - pts[i];
            ld db = sqrtl(d);
            ll aa = d - 1ll * R * R;
            ld a = sqrtl(aa);
            ld y = (ld)aa / (ld)db;
            ld x = (ld)((ld)a * R) / (ld)db;
            ld x1 = pt.x;
            ld y1 = pt.y;
            x1 *= y / db;
            y1 *= y / db;
            ld x2 = -y1;
            ld y2 = x1;
            x2 *= x / y;
            y2 *= x / y;
            ld R1 = atan2(y1 + y2, x1 + x2);
            ld L1 = atan2(y1 - y2, x1 - x2);
            if (L1 > R1) R1 += PI * 2;
            assert(R1 > L1);
            pair<ld, int> kek = {-1, -2};
            for(int k = -4; k <= 4; k += 2) {
                ld L3 = max(L1 + PI * k, L2);
                ld R3 = min(R1 + PI * k, R2);
                kek = max(kek, {R3 - L3, k});
            }
            L2 = max(L2, L1 + PI * kek.second);
            R2 = min(R2, R1 + PI * kek.second);
        }
        for(auto &[ang, j] : to) {
            good[i][j] = false;
            for(int k = -4; k <= 4; k += 2) {
                ld cur = ang + PI * k;
                if (L2 <= cur && cur <= R2) {
                    good[i][j] = true;
                }
            }
        }
    }
    int ans = 0;
    rep(i, n) {
        rep(j, i) {
            if (good[i][j] && good[j][i]) ans++;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}