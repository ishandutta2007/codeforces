#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define ld double
#define ll __int128

mt19937 rnd(51);

const int N = 2e5 + 10, MOD = 998244353, INF = 1e18;
vector<set<pair<int,int>>> st(N);

int mul(int a, int b) {
    return (a * b % MOD);
}

int sum(int a, int b) {
    return a + b >= MOD ? a + b - MOD : a + b;
}

void split(int i, int j) {
    pair<int,int> p = *prev(st[i].upper_bound({j, INF}));
    if (p.first <= j && j <= p.second) {
        if (p.first < j) {
            st[i].erase(p);
            st[i].insert({p.first, j - 1});
            st[i].insert({j, p.second});
        }
    }
}

struct SegTree {
    vector<int> t, len;
    vector<pair<int,int>> add;
    void build(int v, int l, int r) {
        len[v] = r - l + 1;
        if (l == r) return;
        int m = (l + r) / 2;
        build(2 * v, l, m), build(2 * v + 1, m + 1, r);
    }
    SegTree(int n) {
        t.resize(4 * n);
        add.resize(4 * n, {1, 0});
        len.resize(4 * n);
        build(1, 0, n - 1);
    }
    void push(int v) {
        t[v] = sum(mul(t[v], add[v].first), mul(len[v], add[v].second));
        if (v * 2 < add.size()) {
            add[v * 2] = {mul(add[v * 2].first, add[v].first), sum(add[v].second, mul(add[v].first, add[v * 2].second))};
            add[v * 2 + 1] = {mul(add[v * 2 + 1].first, add[v].first), sum(add[v].second, mul(add[v].first, add[v * 2 + 1].second))};
        }
        add[v] = {1, 0};
    }
    void update(int v, int tl, int tr, int l, int r, pair<int,int> p) {
        push(v);
        if (l > r) return;
        if (tl == l && tr == r) {
            if (p.first != -1) {
                add[v].first = mul(add[v].first, p.first);
                add[v].second = mul(add[v].second, p.first);
            }
            if (p.second != -1) {
                add[v].second = sum(add[v].second, p.second);
            }
            push(v);
            return;
        }
        int tm = (tl + tr) / 2;
        update(2 * v, tl, tm, l, min(r, tm), p), update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, p);
        t[v] = sum(t[v * 2], t[v * 2 + 1]);
    }
    int get(int v, int tl, int tr, int l, int r) {
        push(v);
        if (l > r) return 0;
        if (tl == l && tr == r) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return sum(get(2 * v, tl, tm, l, min(r, tm)), get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
    }
};

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        st[i].insert({-1, -1});
        st[i].insert({0, n - 1});
        st[i].insert({n, n});
    }
    SegTree t(n);
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            l--, r--, x--;
            split(x, l);
            split(x, r + 1);
            vector<pair<int,int>> seg;
            while (1) {
                auto it = st[x].lower_bound({l, 0});
                if (it->second <= r) {
                    seg.pb(*it);
                    st[x].erase(*it);
                } else {
                    break;
                }
            }
            if (seg.size() == 0) {
                t.update(1, 0, n - 1, l, r, {2, -1});
            } else {
                if (seg[0].first > l) {
                    t.update(1, 0, n - 1, l, seg[0].first - 1, {2, -1});
                }
                for (int i = 0; i < seg.size(); i++) {
                    t.update(1, 0, n - 1, seg[i].first, seg[i].second, {-1, 1});
                }
                for (int i = 0; i + 1 < seg.size(); i++) {
                    if (seg[i].second + 1 < seg[i + 1].first) {
                        t.update(1, 0, n - 1, seg[i].second + 1, seg[i + 1].first - 1, {2, -1});
                    }
                }
                if (seg.back().second < r) {
                    t.update(1, 0, n - 1, seg.back().second + 1, r, {2, -1});
                }
            }
        } else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << t.get(1, 0, n - 1, l, r) << endl;
        }
    }
    return 0;
}