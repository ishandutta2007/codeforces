#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(51);

#define ll long long
#define pb push_back
#define ld long double

struct SegTree {
    vector<ll> t, cnt, add;
    SegTree(int n) {
        t.resize(4 * n);
        cnt.resize(4 * n);
        add.resize(4 * n);
    }
    void inc(int v, ll val) {
        t[v] += cnt[v] * val;
        add[v] += val;
    }
    void push(int v) {
        inc(v * 2, add[v]);
        inc(v * 2 + 1, add[v]);
        add[v] = 0;
    }
    void update_pos(int v, int l, int r, int pos, int val) {
        if (l == r) {
            cnt[v] ^= 1;
            t[v] = val;
            return;
        }
        push(v);
        int m = (l + r) / 2;
        if (pos <= m) {
            update_pos(2 * v, l, m, pos, val);
        } else {
            update_pos(2 * v + 1, m + 1, r, pos, val);
        }
        t[v] = t[v * 2] + t[v * 2 + 1];
        cnt[v] = cnt[v * 2] + cnt[v * 2 + 1];
    }
    void update(int v, int tl, int tr, int l, int r, ll val) {
        if (l > r) return;
        if (tl == l && tr == r) {
            inc(v, val);
            return;
        }
        push(v);
        int tm = (tl + tr) / 2;
        update(2 * v, tl, tm, l, min(r, tm), val), update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, val);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
    ll get(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (tl == l && tr == r) {
            return t[v];
        }
        push(v);
        int tm = (tl + tr) / 2;
        return get(2 * v, tl, tm, l, min(r, tm)) + get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
    }
};

struct Fenwick {
    vector<int> t;
    Fenwick(int n) {
        t.resize(n);
    }
    void inc(int i, int d) {
        for (; i < t.size(); i = (i | (i + 1))) {
            t[i] += d;
        }
    }
    ll get(int r) {
        ll ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            ans += t[r];
        }
        return ans;
    }
    ll get(int l, int r) {
        return get(r) - get(l - 1);
    }
};

vector<ll> solve(int q, int d, vector<int> b) {
    vector<ll> res;
    ll ans = 0;
    set<int> st;
    int mx = *max_element(b.begin(), b.end()) + 1;
    SegTree t(mx + 1);
    Fenwick f(mx + 1);
    for (auto a : b) {
        if (st.find(a) == st.end()) {
            st.insert(a);
            ans += t.get(1, 0, mx, max(0, a - d), a - 1);
            t.update(1, 0, mx, max(0, a - d), a - 1, 1);
            ll cnt = f.get(a + 1, min(mx, a + d));
            t.update_pos(1, 0, mx, a, cnt);
            ans += cnt * (cnt - 1) / 2;
            f.inc(a, 1);
        } else {
            st.erase(a);
            ans -= t.get(1, 0, mx, max(0, a - d), a - 1);
            t.update(1, 0, mx, max(0, a - d), a - 1, -1);
            ll cnt = f.get(a - d, a - 1), cntt = f.get(a + 1, min(mx, a + d));
            t.update_pos(1, 0, mx, a, 0);
            ans += cnt;
            ans -= cntt * (cntt - 1) / 2;
            f.inc(a, -1);
        }
        res.pb(ans);
    }
    return res;
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q, d;
    cin >> q >> d;
    vector<int> b(q);
    for (int i = 0; i < q; i++) {
        cin >> b[i];
    }
    auto arr = solve(q, d, b);
    for (auto to : arr) {
        cout << to << endl;
    }
    return 0;
}