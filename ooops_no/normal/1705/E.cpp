#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(51);

#define ll long long
#define pb push_back
#define ld long double

const int N = 2e5 + 100;

struct SegTree {
    vector<int> t_min, t_max, add;
    SegTree(int n) {
        t_min.resize(4 * n);
        t_max.resize(4 * n);
        add.resize(4 * n);
    }
    void inc(int v, int val) {
        t_min[v] += val;
        t_max[v] += val;
        add[v] += val;
    }
    void push(int v) {
        inc(v * 2, add[v]);
        inc(v * 2 + 1, add[v]);
        add[v] = 0;
    }
    void update(int v, int tl, int tr, int l, int r, int val) {
        if (l > r) return;
        if (tl == l && tr == r) {
            inc(v, val);
            return;
        }
        push(v);
        int tm = (tl + tr) / 2;
        update(2 * v, tl, tm, l, min(r, tm), val), update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, val);
        t_min[v] = min(t_min[v * 2], t_min[v * 2 + 1]);
        t_max[v] = max(t_max[v * 2], t_max[v * 2 + 1]);
    }
    int get_last_one(int v, int l, int r) {
        if (t_max[v] == 0) return -1;
        if (l == r) {
            return l;
        }
        push(v);
        int m = (l + r) / 2;
        int res = get_last_one(2 * v + 1, m + 1, r);
        return (res == -1 ? get_last_one(2 * v, l, m) : res);
    }
    int get_first_one(int v, int l, int r, int i) {
        if (t_max[v] == 0 || r < i) return -1;
        if (l == r) {
            return l;
        }
        push(v);
        int m = (l + r) / 2;
        int res = get_first_one(2 * v, l, m, i);
        return (res == -1 ? get_first_one(2 * v + 1, m + 1, r, i) : res);
    }
    int get_first_zero(int v, int l, int r, int i) {
        if (t_min[v] == 1 || r < i) return -1;
        if (l == r) {
            return l;
        }
        push(v);
        int m = (l + r) / 2;
        int res = get_first_zero(2 * v, l, m, i);
        return (res == -1 ? get_first_zero(2 * v + 1, m + 1, r, i) : res);
    }
} t(N);

void add(int a) {
    int i = t.get_first_zero(1, 0, N - 1, a);
    t.update(1, 0, N - 1, i, i, 1);
    t.update(1, 0, N - 1, a, i - 1, -1);
}

void del(int a) {
    int i = t.get_first_one(1, 0, N - 1, a);
    t.update(1, 0, N - 1, i, i, -1);
    t.update(1, 0, N - 1, a, i - 1, 1);
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        add(a[i]);
    }
    for (int i = 0; i < q; i++) {
        int k, l;
        cin >> k >> l;
        k--;
        del(a[k]);
        a[k] = l;
        add(a[k]);
        cout << t.get_last_one(1, 0, N - 1) << endl;
    }
    return 0;
}