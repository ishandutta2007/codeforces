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
const int maxN = 1e6 + 30;
const int LG = 100;

struct fenwick {
    int n{};
    vector<ll> fenw{};

    void build(int k) {
        n = k;
        fenw.resize(n);
    }

    void upd(int i, ll x) {
        for (; i < n; i = i | (i + 1)) fenw[i] += x;
    }

    ll get(int i) {
        ll res = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1) res += fenw[i];
        return res;
    }

    ll get(int l, int r) {
        if (l > r) return 0;
        return get(r) - get(l - 1);
    }

    void upd(int l, int r, ll x) {
        upd(l, x);
        upd(r, -x);
    }
};

void solve() {
    set<ar<int, 3>> segs;
    int n, q;
    cin >> n >> q;
    segs.insert({0, n, 1});
    vector<ll> add(n + 1);
    fenwick f;
    f.build(n);

    auto del = [&](int l, int r, int c) {
        f.upd(l, r, add[c]);
    };

    auto create = [&](int l, int r, int c) {
        f.upd(l, r, -add[c]);
        segs.insert({l, r, c});
    };


    rep(_, q) {
        string s;
        cin >> s;
        if (s[0] == 'C') {
            int l, r, c;
            cin >> l >> r >> c;
            l--;
            ar<int, 3> tmp = {l + 1, -1, -1};
            auto it = segs.lower_bound(tmp);
            it--;
            while (it != segs.end() && it->front() < r) {
                auto cur = *it;
                it = segs.erase(it);
                del(cur[0], cur[1], cur[2]);
                if (cur[0] < l) {
                    create(cur[0], l, cur[2]);
                }
                if (cur[1] > r) {
                    create(r, cur[1], cur[2]);
                }
            }
            create(l, r, c);
        } else if (s[0] == 'A') {
            int c, x;
            cin >> c >> x;
            add[c] += x;
        } else {
            int i;
            cin >> i;
            i--;
            ar<int, 3> tmp = {i + 1, -1, -1};
            auto it = prev(segs.lower_bound(tmp));
            int c = (*it)[2];
            cout << f.get(i) + add[c] << '\n';
        }
    }
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