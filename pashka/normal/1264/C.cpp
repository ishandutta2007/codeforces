#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka


#define MOD 998244353

long sum(long a, long b) {
    long res = (a + b) % MOD;
    if (res < 0) res += MOD;
    return res;
}

long mult(long a, long b) {
    long res = (a * b) % MOD;
    if (res < 0) res += MOD;
    return res;
}

long power(long a, long b) {
    a %= MOD;
    if (a < 0) a += MOD;
    long res = 1;
    while (b > 0) {
        if (b & 1) {
            res = mult(res, a);
        }
        a = mult(a, a);
        b >>= 1;
    }
    return res;
}

long inv(long a) {
    return power(a, MOD - 2);
}


struct segtree {

    struct item {
        long sum, mult, sumprog;
        int num;
    };

    item zeroSum = {0, 1, 0, 0};

    item sum(item a, item b) {
        item res;
        res.sum = ::sum(a.sum, mult(a.mult, b.sum));
        res.mult = ::mult(a.mult, b.mult);
        res.sumprog = ::sum(a.sumprog,
                            ::mult(a.mult, ::sum(b.sumprog, ::mult(b.sum, a.num))));
        res.num = a.num + b.num;
        return res;
    }

    vector<item> sums;

    int size;

    item sum(int l, int r, int n, int L, int R) {
        if (l >= R || L >= r) return zeroSum;
        if (L >= l && R <= r) {
            return sums[n];
        }
        int M = (L + R) >> 1;
        return sum(sum(l, r, 2 * n + 1, L, M), sum(l, r, 2 * n + 2, M, R));
    }

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        sums.assign(2 * size, zeroSum);
    }

    void init(vector<item> a) {
        int n = a.size();
        init(n);
        size = 1;
        while (size < n) size *= 2;
        sums.assign(2 * size, zeroSum);
        for (int i = 0; i < n; i++) {
            sums[size - 1 + i] = a[i];
        }
        for (int i = size - 2; i >= 0; i--) {
            sums[i] = sum(sums[2 * i + 1], sums[2 * i + 2]);
        }
    }

    item sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
};

segtree st;

long calc(int l, int r) {
    auto res = st.sum(l, r);
    long s = mult(sum(res.sumprog, mult(res.mult, res.num)), inv(res.mult));
//    cout << l << " " << r << " " << res.sum << " "  << "\n";
    return s;
}

int main() {
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    vector<long> a(n);
    long inv100 = inv(100);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = mult(a[i], inv100);
    }

    vector<segtree::item> items(n);
    for (int i = 0; i < n; i++) {
        items[i] = {sum(-a[i], 1), a[i], sum(-a[i], 1), 1};
    }
    st.init(items);

    set<int> z;
    z.insert(0);
    z.insert(n);
    vector<long> pc(n);
    long res = calc(0, n);
    pc[0] = res;
//    cout << res << "\n";
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        x--;
        auto p = z.lower_bound(x);
        if (*p == x) {
            --p;
            int prev = *p;
            ++p;
            ++p;
            int next = *p;
            z.erase(x);

            res = sum(res, -pc[prev]);
            res = sum(res, -pc[x]);
            pc[prev] = calc(prev, next);
            res = sum(res, pc[prev]);
        } else {
            int next = *p;
            --p;
            int prev = *p;
            z.insert(x);
            res = sum(res, -pc[prev]);
            pc[prev] = calc(prev, x);
            pc[x] = calc(x, next);
            res = sum(res, pc[prev]);
            res = sum(res, pc[x]);
        }
        cout << res << "\n";
    }

    return 0;
}