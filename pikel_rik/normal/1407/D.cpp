#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 3e5 + 5;

template <typename T>
class SegmentTree {
public:
    using F = function<T(const T&, const T&)>;

    int n;
    vector<T> t;
    T e;
    F f;
    SegmentTree() : n(), t(), e(), f() {}

    template <typename U>
    SegmentTree(const U& arr, int n, T e, F f): n(n), t(4 * n), e(e), f(f) {
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

    template <typename U>
    void update(int idx, U val) {
        updateHelper(idx, val, 1, 0, n - 1);
    }

    template <typename U>
    void updateHelper(int idx, U val, int i, int l, int r) {
        if (l == r) {
            t[i] = T(val);
            return;
        }
        int mid = (l + r) >> 1;
        if (idx <= mid)
            updateHelper(idx, val, i << 1, l, mid);
        else updateHelper(idx, val, i << 1 | 1, mid + 1, r);

        t[i] = f(t[i << 1], t[i << 1 | 1]);
    }

    T query(int ql, int qr) {
        return queryHelper(ql, qr, 1, 0, n - 1);
    }

    T queryHelper(int ql, int qr, int i, int l, int r) {
        if (ql > r or qr < l)
            return e;
        if (ql <= l and r <= qr)
            return t[i];
        int mid = (l + r) >> 1;
        T x = queryHelper(ql, qr, i << 1, l, mid), y = queryHelper(ql, qr, i << 1 | 1, mid + 1, r);
        return f(x, y);
    }
};

int n, a[N], dp[N];

void print(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << ' ' << a[s.top()] << '\n';
        s.pop();
    }
    cout << "bruh" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    dp[0] = 0;
    vector<int> v1, v2;

    SegmentTree<int> st1(vector<int>(n, INT_MAX), n, INT_MAX, [&] (int x, int y) {
        return x < y ? x : y;
    });
    SegmentTree<int> st2(vector<int>(n, INT_MAX), n, INT_MAX, [&] (int x, int y) {
        return x < y ? x : y;
    });

    for (int i = 1; i < n; i++) {
        v1.push_back(i - 1);
        v2.push_back(i - 1);
        st1.update(v1.size() - 1, dp[i - 1]);
        st2.update(v2.size() - 1, dp[i - 1]);

        if (a[i] == a[i - 1]) {
            dp[i] = dp[i - 1] + 1;
        } else {
            if (a[i - 1] > a[i]) {
                int lo = 0, hi = v1.size() - 1;
                while (lo < hi) {
                    int mid = lo + (hi - lo + 1) / 2;
                    if (a[v1[mid]] <= a[i])
                        lo = mid;
                    else hi = mid - 1;
                }
                dp[i] = st1.query(lo, v1.size() - 1) + 1;
            } else {
                int lo = 0, hi = v2.size() - 1;
                while (lo < hi) {
                    int mid = lo + (hi - lo + 1) / 2;
                    if (a[v2[mid]] >= a[i])
                        lo = mid;
                    else hi = mid - 1;
                }
                dp[i] = st2.query(lo, v2.size() - 1) + 1;
            }
        }

        while (!v1.empty() and a[v1.back()] >= a[i]) {
            v1.pop_back();
        }
        while (!v2.empty() and a[v2.back()] <= a[i]) {
            v2.pop_back();
        }
    }

    cout << dp[n - 1] << '\n';
//    for (int i = 0; i < n; i++) {
//        cout << dp[i] << ' ';
//    }
//
//    for (int i = 1; i < n; i++) {
//        dp[i] = dp[i - 1] + 1;
//        int mn = a[i - 1], mx = a[i - 1];
//
//        for (int j = i - 2; j >= 0; j--) {
//            if (min(a[i], a[j]) > mx)
//                dp[i] = min(dp[i], dp[j] + 1);
//            if (max(a[i], a[j]) < mn)
//                dp[i] = min(dp[i], dp[j] + 1);
//            mx = max(mx, a[j]);
//            mn = min(mn, a[j]);
//        }
//    }
//
//    cout << '\n';
//    for (int i = 0; i < n; i++) {
//        cout << dp[i] << ' ';
//    }
    return 0;
}