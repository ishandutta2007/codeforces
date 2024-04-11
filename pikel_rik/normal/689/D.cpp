#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 2e5 + 5;

template <typename T, bool I = true, typename F = function<T(const T&, const T&)>> class SparseTable {
public:
    int n;
    vector<vector<T>> mat;
    vector<int> log;
    F f;

    SparseTable(): n(), mat(), log(), f() {}
    template <typename U> void build(const U& arr, int _n, F func) {
        n = _n;
        mat.resize((int)log2(n) + 1);
        f = func;

        if (I) {
            log.resize(n + 1);
            log[1] = 0;
            for (int i = 2; i <= n; i++) {
                log[i] = 1 + log[i >> 1];
            }
        }

        mat[0].resize(n);
        for (int i = 0; i < n; i++)
            mat[0][i] = T(arr[i]);

        for (int j = 1; j < mat.size(); j++) {
            mat[j].resize(n - j);
            for (int i = 0; i + (1 << j) <= n; i++) {
                mat[j][i] = f(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    T query(int l, int r) {
        if (I) {
            int j = log[r - l + 1];
            return f(mat[j][l], mat[j][r + 1 - (1 << j)]);
        }

        T ans = 0;
        for (int j = mat.size() - 1; j >= 0; j--) {
            if ((1 << j) <= r - l + 1) {
                ans = f(ans, mat[j][l]);
                l += (1 << j);
            }
        }
        return ans;
    }
};

int n, a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    SparseTable<int> st1, st2;
    st1.build(a, n, [&] (int x, int y) {
        return max(x, y);
    });

    st2.build(b, n, [&] (int x, int y) {
        return min(x, y);
    });

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int lo = i, hi = n - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (st1.query(i, mid) - st2.query(i, mid) > 0)
                hi = mid - 1;
            else lo = mid;
        }

        int rmax = lo;

        lo = i; hi = n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (st1.query(i, mid) - st2.query(i, mid) >= 0)
                hi = mid;
            else lo = mid + 1;
        }

        int rmin = lo;
        if (st1.query(i, rmin) == st2.query(i, rmin))
            ans += (rmax - rmin + 1);
    }

    cout << ans << "\n";
    return 0;
}