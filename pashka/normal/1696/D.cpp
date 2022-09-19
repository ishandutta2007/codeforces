#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

struct segtree {
    typedef long item;

    item zeroSum = LLONG_MAX;

    item sum(item a, item b) {
        return min(a, b);
    }

    vector<item> sums;

    int size;

    void set(int i, item x, int n, int L, int R) {
        if (R == L + 1) {
            sums[n] = x;
            return;
        }
        int M = (L + R) >> 1;
        if (i < M) {
            set(i, x, 2 * n + 1, L, M);
        } else {
            set(i, x, 2 * n + 2, M, R);
        }
        sums[n] = sum(sums[2 * n + 1], sums[2 * n + 2]);
    }

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

    void set(int i, item x) {
        set(i, x, 0, 0, size);
    }

    item sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
};

struct test {
    void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        segtree stg, stl;
        stg.init(n);
        stl.init(n);
        stg.set(0, 0);
        stl.set(0, 0);
        vector<int> sg = {-1, 0}, sl = {-1, 0};
        for (int i = 1; i < n; i++) {
            while (sl.back() >= 0 && a[sl.back()] > a[i]) {
                stl.set(sl.back(), LLONG_MAX);
                sl.pop_back();
            }
            while (sg.back() >= 0 && a[sg.back()] < a[i]) {
                stg.set(sg.back(), LLONG_MAX);
                sg.pop_back();
            }

            long x;
            if (a[i] < a[i - 1]) {
                x = stg.sum(sl.back() + 1, n) + 1;
            } else {
                x = stl.sum(sg.back() + 1, n) + 1;
            }
            stg.set(i, x);
            stl.set(i, x);
            sg.push_back(i);
            sl.push_back(i);
        }
        cout << stg.sum(n - 1, n) << "\n";
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        test t;
        t.solve();
    }

    return 0;
}