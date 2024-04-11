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
const int maxN = 100;
const int LG = 20;


struct pt {
    ll x = 0, y = 0;
};

bool operator<(const pt &a, const pt &b) {
    return tie(a.x, a.y) < tie(b.x, b.y);
}

bool operator==(const pt &a, const pt &b) {
    return tie(a.x, a.y) == tie(b.x, b.y);
}

pt operator*(const pt &a, const ll &b) {
    return {a.x * b, a.y * b};
}

pt operator/(const pt &a, const ll &b) {
    return {a.x / b, a.y / b};
}

pt operator+(const pt &a, const pt &b) {
    return {a.x + b.x, a.y + b.y};
}

pt operator-(const pt &a, const pt &b) {
    return {a.x - b.x, a.y - b.y};
}

// - 
ll operator*(const pt &a, const pt &b) {
    return a.x * b.y - a.y * b.x;
}

//
ll operator%(const pt &a, const pt &b) {
    return a.x * b.x + a.y * b.y;
}

ll dist(const pt &a) {
    return a.x * a.x + a.y * a.y;
}

vector<pt> ConvexHull(vector<pt> pts) {
    int min_idx = min_element(all(pts)) - pts.begin();
    swap(pts[0], pts[min_idx]);

    sort(pts.begin() + 1, pts.end(), [&](const pt &a, const pt &b) {
        if ((a - pts[0]) * (b - pts[0])) return (a - pts[0]) * (b - pts[0]) > 0;
        return (a - pts[0]) % (a - pts[0]) < (b - pts[0]) % (b - pts[0]);
    });
    vector<pt> convex_hull = {pts[0]};
    int sz = 0;
    for (int i = 1; i < (int) pts.size(); ++i) {
        while (sz && (convex_hull[sz] - convex_hull[sz - 1]) * (pts[i] - convex_hull[sz]) <= 0) {
            convex_hull.pop_back();
            --sz;
        }
        convex_hull.push_back(pts[i]);
        ++sz;
    }
    return convex_hull;
}

vector<int> Zfunc(vl &a) {
    int n = a.size();
    vi z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i < r) z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && a[z[i]] == a[i + z[i]]) z[i]++;
        if (i + z[i] > r) {
            r = i + z[i];
            l = i;
        }
    }
    return z;
}

void solve() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vec<pt> a(n), b(m);
    rep(i, n) cin >> a[i].x >> a[i].y;
    rep(i, m) cin >> b[i].x >> b[i].y;
    auto A = ConvexHull(a);
    auto B = ConvexHull(b);

    auto check = [](vector<pt> A, vector<pt> B, bool flag) {

        auto get_polygon = [&](vector<pt> &C) {
            vector<ll> res;
            for (int i = 0; i < (int) C.size(); ++i) {
                pt X = C[i];
                pt Y = C[(i + 1) % (int) C.size()];
                res.push_back(dist(Y - X));
                pt Z = C[(i + 2) % (int) C.size()];
                if (flag) res.push_back((Z - Y) * (X - Y));
                else res.push_back((Z - Y) % (X - Y));
            }
            return res;
        };

        auto Ap = get_polygon(A);
        auto Bp = get_polygon(B);
        if (Ap.size() != Bp.size()) return false;

        int sz = Ap.size();
        Ap.push_back(-INF);
        rep(_, 2) {
            for (auto &x : Bp) Ap.push_back(x);
        }
        auto z = Zfunc(Ap);
        for (int i = sz + 1; i < (int) Ap.size(); i += 2) {
            if (z[i] >= sz) {
                return true;
            }
        }
        return false;
    };
    if (check(A, B, true)) {
        if (!check(A, B, false)) {
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
        return;
    }
    reverse(all(B));
    if (check(A, B, true)) {
        if (!check(A, B, false)) {
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
        return;
    }
    cout << "NO\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(20 - 7) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}