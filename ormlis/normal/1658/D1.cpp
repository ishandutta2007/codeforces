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

using int128 = __int128;
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
const int maxN = 4e5 + 10;
const int LG = 17;
const int md = 998244353;

struct kek {
    vi c;
    int l1;
    int r1;
};

void solve() {
    int l, r;
    cin >> l >> r;
    int n = r - l + 1;
    vi a(n);
    rep(i, n) {
        cin >> a[i];
    }
    int x = 0;
    vector<kek> cur;
    {
        kek f;
        f.c = a;
        f.l1 = l;
        f.r1 = r;
        cur.push_back(f);
    }
    for (int b = LG - 1; b >= 0; --b) {
        vector<kek> nxt;
        for (auto &g : cur) {
            vi c = g.c;
            if (c.empty()) continue;
            int l1 = g.l1;
            int r1 = g.r1;
            int cnt = 0;
            int mid = r1;
            for (int i = l1; i <= r1; ++i) {
                if ((1 << b) & i) {
                    cnt++;
                }
                if ((1 << b) & (i ^ (i + 1))) {
                    mid = i;
                }
            }
            for (auto &v : c) {
                if (v & (1 << b)) {
                    cnt--;
                } else {
                }
            }
            if (cnt != 0) x |= (1 << b);
        }
        for (auto &g : cur) {
            vi c = g.c;
            if (c.empty()) continue;
            int l1 = g.l1;
            int r1 = g.r1;
            int cnt = 0;
            int mid = r1;
            for (int i = l1; i <= r1; ++i) {
                if ((1 << b) & i) {
                    cnt++;
                }
                if ((1 << b) & (i ^ (i + 1))) {
                    mid = i;
                }
            }
            vi m1, m2;
            for (auto &v : c) {
                if (v & (1 << b)) {
                    m1.push_back(v);
                    cnt--;
                } else {
                    m2.push_back(v);
                }
            }
            if ((1 << b) & x) swap(m1, m2);
            if (b == 0) continue;
            kek f1, f2;
            f1.c = m1;
            f2.c = m2;
            if ((1 << b) & l1) {
                f1.l1 = l1;
                f1.r1 = mid;
                f2.l1 = mid + 1;
                f2.r1 = r1;
            } else {
                f2.l1 = l1;
                f2.r1 = mid;
                f1.l1 = mid + 1;
                f1.r1 = r1;
            }
            nxt.push_back(f1);
            nxt.push_back(f2);
        }
    }
    cout << x << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}