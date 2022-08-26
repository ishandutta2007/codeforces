#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

/*
using namespace __gnu_pbds;

typedef tree<
        pair<int, int>,
        null_type,
        less<pair<int, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
*/

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const int INFi = 1e9 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;
const int maxN = 2e6 + 1;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

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
};

struct SuperFenwick {
    fenwick f1, f2;
    vector<ll> xx;

    void build(vector<ll> &a) {
        int n = a.size();
        xx = a;
        f1.build(n);
        f2.build(n);
    }

    void upd(ll l, ll r, ll x) {
        int lq = lower_bound(all(xx), l) - xx.begin();
        int rq = lower_bound(all(xx), r) - xx.begin();
        // (i - l) * x
        f1.upd(lq, x);
        f1.upd(rq + 1, -x);
        f2.upd(lq, -1ll * l * x);
        f2.upd(rq + 1, 1ll * r * x);
    }

    ll get(ll x) {
        int i = lower_bound(all(xx), x) - xx.begin();
        return f1.get(i) * xx[i] + f2.get(i);
    }

    ll get1(int i) {
        return f1.get(i) * xx[i] + f2.get(i);
    }
} sf;

vector<ll> xx;
struct Node {
    pair<ll, int> value;
    int l, r;
};

Node t[maxN];

void build(int v, int l, int r) {
    t[v].l = l;
    t[v].r = r;
    if (l + 1 == r) {
        t[v].value = {sf.get1(l), l};
        return;
    }
    build(v << 1, l, (l + r) >> 1);
    build(v << 1 | 1, (l + r) >> 1, r);
    t[v].value = min(t[v << 1].value, t[v << 1 | 1].value);
}

void check(int v) {
    int i = t[v].value.second;
    t[v].value = {INF, INFi};
    for (auto ch : {i, t[v].l, t[v].r - 1}) {
        t[v].value = min(t[v].value, {sf.get1(ch), ch});
    }
}

void upd(int v, int l, int r, int lq, int rq) {
    check(v);
    if (lq >= r || l >= rq) return;
    if (lq <= l && r <= rq) return;
    upd(v << 1, l, (l + r) >> 1, lq, rq);
    upd(v << 1 | 1, (l + r) >> 1, r, lq, rq);
    t[v].value = min(t[v << 1].value, t[v << 1 | 1].value);
}

void upd(ll lq, ll rq) {
    int lqq = lower_bound(all(xx), lq) - xx.begin();
    int rqq = lower_bound(all(xx), rq) - xx.begin();
    upd(1, 0, xx.size(), lqq, rqq + 1);
}

int get(int v, int l, int r, int lq, int rq, ll value) {
    if (lq >= r || l >= rq) return INFi;
    check(v);
    if (t[v].value.first > value) return INFi;
    if (l + 1 == r) return l;
    int x = get(v << 1, l, (l + r) >> 1, lq, rq, value);
    if (x != INFi) return x;
    return get(v << 1 | 1, (l + r) >> 1, r, lq, rq, value);
}

int get(ll lq, ll rq, ll value) {
    int lqq = lower_bound(all(xx), lq) - xx.begin();
    int rqq = lower_bound(all(xx), rq) - xx.begin();
    value = sf.get1(lqq) - value;
    return get(1, 0, (int) xx.size(), lqq, rqq + 1, value);
}

void solve() {
    int q;
    cin >> q;
    vector<ar<int, 4>> qs(q);
    range(i, q) {
        int t;
        cin >> t;
        qs[i][0] = t;
        if (t == 1) {
            cin >> qs[i][1] >> qs[i][2];
        } else if (t == 2) {
            cin >> qs[i][1];
        } else {
            cin >> qs[i][1] >> qs[i][2] >> qs[i][3];
            xx.push_back(qs[i][2]);
        }
        xx.push_back(qs[i][1]);
    }
    xx.push_back(INFi);
    xx.push_back(-INFi);
    sort(all(xx));
    xx.resize(unique(all(xx)) - xx.begin());
    sf.build(xx);
    build(1, 0, xx.size());
    map<ll, ll> mp;
    mp[INFi] = mp[-INFi] = 0;
    for (auto &[tt, l, r, v] : qs) {
        if (tt == 1) {
            ll s = r;
            auto it = mp.lower_bound(l);
            assert(it != mp.begin());
            it--;
            s -= it->second;
            it++;
            sf.upd(l, it->first, s);
            upd(l, it->first);
            mp[l] = r;
        } else if (tt == 2) {
            auto it = mp.find(l);
            ll s = -it->second;
            assert(it != mp.begin());
            it--;
            s += it->second;
            it++;
            it++;
            assert(it != mp.end());
            sf.upd(l, it->first, s);
            upd(l, it->first);
            it--;
            mp.erase(it);
        } else if (tt == 3) {
            if (v == 0) {
                cout << l << '\n';
                continue;
            }
            l = mp.lower_bound(l)->first;
            int i = get(l, r, v);
            if (i == INFi) {
                cout << "-1\n";
                continue;
            }
            ll d = sf.get1(i) - sf.get(l);
            if (d == -v) {
                cout << xx[i] << '\n';
                continue;
            }
            assert(d < -v);
            auto it = mp.lower_bound(xx[i]);
            it--;
            ll s = it->second;
            ld can = (ld) (-v - d) / (ld) (-s);
            cout << (ld) xx[i] - can << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}