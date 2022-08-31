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
using i128 = __int128;
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
const int maxN = 3e5 + 20;


struct dsu {
    vector<int> dsu;
    int n;

    int get_dsu(int a) {
        if (dsu[a] == a) return a;
        return dsu[a] = get_dsu(dsu[a]);
    }

    void build(int k) {
        n = k;
        dsu.resize(n);
        range(i, n)
            dsu[i] = i;
    }

    bool unio(int a, int b) {
        a = get_dsu(a), b = get_dsu(b);
        if (rand() % 2) {
            swap(a, b);
        }
        dsu[a] = b;
        return a == b;
    }
};

void solve() {
    int n; cin >> n;
    vvi good(n, vi(n));
    rep(i, n) {
        for(int j = i; j < n; ++j) {
            char x; cin >> x;
            good[i][j] = x - '0';
        }
    }
    dsu d;
    d.build(n);
    auto create_edge = [&] (int x, int y) {
        cout << x + 1 << ' ' << y + 1 << '\n';
        d.unio(x, y);
    };
    rep(len, n) {
        for(int l = 0, r = len; r < n; l++, r++) {
            if (!good[l][r] || d.get_dsu(l) == d.get_dsu(r)) continue;
            vpi segs;
            for(int i = l; i <= r; ++i) {
                if (segs.empty() || d.get_dsu(segs.back().second) != d.get_dsu(i)) segs.emplace_back(i, i);
                segs.back().second = i;
            }
            auto unio = [&] (pi a, pi b) { create_edge(min(a.first, b.first), max(a.second, b.second)); };
            vpi segs2;
            for(int L = 0, R = (int)segs.size() - 1; L <= R; ) {
                segs2.push_back(segs[L++]);
                if (L <= R) segs2.push_back(segs[R--]);
            }
            rotate(segs2.begin(), segs2.end() - 1, segs2.end());
            rep(i, (int)segs2.size() - 1) unio(segs2[i], segs2[i + 1]);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    //cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}