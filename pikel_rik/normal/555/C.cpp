#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

template <typename T>
class SegmentTree {
public:
    using F = function<T(const T&, const T&)>;

    int n;
    vector<T> t;
    vector<int> lazy;
    T e;
    F f;
    SegmentTree() : n(), t(), lazy(), e(), f() {}

    template <typename U>
    SegmentTree(const U& arr, int n, T e, F f): n(n), t(4 * n), lazy(4 * n), e(e), f(f) {
        build(arr, 1, 0, n - 1);
    }

    template <typename U>
    void build(const U& arr, int i, int l, int r) {
        if (l == r) {
            t[i] = T(arr[l]);
            return;
        }

        int mid = (l + r) >> 1;
        build(arr, i << 1, l, mid);
        build(arr, i << 1 | 1, mid + 1, r);

        t[i] = f(t[i << 1], t[i << 1 | 1]);
    }

    void push (int x, int l, int r) {
        if (lazy[x]) {
            t[x << 1] = min(t[x << 1], lazy[x]);
            t[x << 1 | 1] = min(t[x << 1 | 1], lazy[x]);
            lazy[x << 1] = (lazy[x << 1] ? min(lazy[x << 1], lazy[x]) : lazy[x]);
            lazy[x << 1 | 1] = (lazy[x << 1 | 1] ? min(lazy[x << 1 | 1], lazy[x]) : lazy[x]);
            lazy[x] = 0;
        }
    }

    template <typename U>
    void update(int ql, int qr, U val) {
        updateHelper(ql, qr, val, 1, 0, n - 1);
    }

    template <typename U>
    void updateHelper(int ql, int qr, U val, int i, int l, int r) {
        if (ql > r or qr < l)
            return;
        if (ql <= l and r <= qr) {
            t[i] = min(t[i], val);
            lazy[i] = (lazy[i] ? min(lazy[i], val) : val);
            return;
        }
        push(i, l, r);
        int mid = (l + r) >> 1;
        updateHelper(ql, qr, val, i << 1, l, mid);
        updateHelper(ql, qr, val, i << 1 | 1, mid + 1, r);

        t[i] = f(t[i << 1], t[i << 1 | 1]);
    }

    T query(int idx) {
        return queryHelper(idx, 1, 0, n - 1);
    }

    T queryHelper(int idx, int i, int l, int r) {
        if (l == r)
            return t[i];
        push(i, l, r);
        int mid = (l + r) >> 1;
        if (idx <= mid)
            return queryHelper(idx, i << 1, l, mid);
        return queryHelper(idx, i << 1 | 1, mid + 1, r);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<pair<int, char>> queries;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        char c;
        cin >> c;
        queries.emplace_back(x, c);
    }

    vector<int> temp;
    for (int i = 0; i < q; i++) {
        temp.push_back(queries[i].first);
    }

    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    SegmentTree<int> st1(vector<int>(temp.size(), (int)2e9), temp.size(), (int)2e9, [&] (int x, int y) {
        return x < y ? x : y;
    });
    SegmentTree<int> st2(vector<int>(temp.size(), (int)2e9), temp.size(), (int)2e9, [&] (int x, int y) {
        return x < y ? x : y;
    });

    set<int> visited;

    for (auto& [x, c] : queries) {
        int idx = lower_bound(temp.begin(), temp.end(), x) - temp.begin();
        if (visited.count(x)) {
            cout << "0\n";
            continue;
        }
        if (c == 'U') {
            int first = st1.query(idx);
            if (first == (int)2e9) {
                cout << n - x + 1 << '\n';
                st2.update(idx, temp.size() - 1, -x);
            } else {
                cout << first - x << '\n';
                first = lower_bound(temp.begin(), temp.end(), first) - temp.begin();
                st2.update(idx, first, -x);
            }
        } else {
            int last = -st2.query(idx);
            if (last == (int)-2e9) {
                cout << x << '\n';
                st1.update(0, idx, x);
            } else {
                cout << x - last << '\n';
                last = lower_bound(temp.begin(), temp.end(), last) - temp.begin();
                st1.update(last, idx, x);
            }
        }
        visited.insert(x);
    }
    return 0;
}