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

const int INFi = 1e9 + 10;
const ll INF = 2e18;
const int maxN = 5e6 + 30;
const int LG = 100;


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
        range(i, n)dsu[i] = i;
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
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    vpi ans;
    auto check = [&](vpi &cur) {
        dsu d;
        d.build(n + 30);
        rep(i, n) {
            rep(j, 30) {
                if (a[i] & (1 << j)) d.unio(i, n + j);
            }
        }
        bool need = false;
        if (d.get_dsu(0) != d.get_dsu(n)) need = true;
        for (int i = 1; i < n; ++i) {
            if (d.get_dsu(i) == d.get_dsu(0)) continue;
            if (need) {
                d.unio(0, n);
                cur.emplace_back(0, 0);
                need = false;
                if (d.get_dsu(i) == d.get_dsu(0)) continue;
            }
            d.unio(i, n);
            cur.emplace_back(i, 0);
        }
    };
    check(ans);
    rep(t, n) {
        int was = a[t];
        vpi cur;
        while (a[t] > 1) {
            a[t]--;
            cur.emplace_back(t, 1);
            if (a[t] & 1) {
                auto nxt = cur;
                check(nxt);
                if (nxt.size() < ans.size()) ans = nxt;
            }
            int b = __builtin_ctz(a[t]);
            int need = a[t] & (a[t] + 1);
            int k = a[t] - need;
            if (cur.size() + k >= min((int) ans.size(), b)) break;
            rep(_, k) a[t]--;
        }
        a[t] = was;
    }
    cout << ans.size() << '\n';
    for (auto &[x, y] : ans) {
        if (y == 0) a[x]++;
        else a[x]--;
    }
    rep(i, n) cout << a[i] << ' ';
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}