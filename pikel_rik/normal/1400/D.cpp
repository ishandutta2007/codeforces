#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 3000 + 5;

template <typename T> class FenwickTree {
public:
    using F = function<T(const T&, const T&)>;

    int n;
    vector<T> bit;
    F f;

    FenwickTree(): n(), bit(), f() {}
    explicit FenwickTree(int n, F f = plus<T>()): n(n), bit(n + 1, 0), f(f) {}

    void add(int i, int val) {
        while (i <= n) {
            bit[i] = f(bit[i], val);
            i += i & -i;
        }
    }
    T query(int i) {
        T ans = T();
        while (i > 0) {
            ans = f(ans, bit[i]);
            i -= i & -i;
        }
        return ans;
    }
};

int n, a[N], cnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i], cnt[i] = 0;

        ll ans = 0;
        FenwickTree<int> ft(n);

        for (int i = 1; i <= n; i++) {
            for (int j = i - 1; j >= 1; j--) {
                if (a[i] == a[j]) {
                    ans += ft.query(j) - cnt[j];
                    ft.add(j, 1);
                    cnt[j]++;
                    ft.add(i, -1);
                }
            }
        }

        cout << ans << "\n";
    }
    return 0;
}