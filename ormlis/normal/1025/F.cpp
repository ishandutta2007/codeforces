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

struct pt {
    int x, y;
};

pt operator - (const pt &a, const pt &b) {
    return {a.x - b.x, a.y - b.y};
}

pt operator + (const pt &a, const pt &b) {
    return {a.x + b.x, a.y + b.y};
}

ll operator * (const pt &a, const pt &b) {
    return 1ll * a.x * b.y - 1ll * a.y * b.x;
}

ll operator % (const pt &a, const pt &b) {
    return 1ll * a.x * b.x + 1ll * a.y * b.y;
}

bool comp(pt a, pt b) {
    bool up1 = (a.y > 0 || (a.y == 0 && a.x > 0));
    bool up2 = (b.y > 0 || (b.y == 0 && b.x > 0));
    if (up1 != up2) return up1;
    return (a * b) > 0;
}

void solve() {
    int n; cin >> n;
    vec<pt> pts(n);
    rep(i, n) cin >> pts[i].x >> pts[i].y;
    ll answer = 0;
    rep(i, n) {
        vi ord(n);
        iota(all(ord), 0);
        iota(ord.begin() + i, ord.end(), i + 1);
        ord.pop_back();
        sort(all(ord), [&] (const int &a, const int &b) {return comp(pts[a] - pts[i], pts[b] - pts[i]);});
        int sz = n - 1;
        rep(j, sz) ord.push_back(ord[j]);
        int e = 0;
        rep(j, sz) {
            e = max(e, j + 1);
            while(e < j + sz && (pts[ord[j]] - pts[i]) * (pts[ord[e]] - pts[i]) > 0) e++;
            int cntL = e - j - 1;
            int cntR = n - 2 - cntL;
            if (cntL <= 1 || cntR <= 1) continue;
            answer += 1ll * cntL * (cntL - 1) * cntR * (cntR - 1) / 4;
        }
    }
    cout << answer / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    // cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}