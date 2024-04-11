#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e5 + 5;

template <typename T, bool I = true> class SparseTable {
public:
    int n;
    vector<vector<T>> mat;
    vector<int> log;
    function<T(const T&, const T&)> f;

    SparseTable(): n(), mat(), log(), f() {}
    template <typename U> void build(const U& arr, int _n, function<T(const T&, const T&)> func) {
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

int n, s, l, a[N], dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> s >> l;
    for (int i = 0; i < n; i++) cin >> a[i];

    SparseTable<int> st1, st2;
    st1.build(a, n, [&] (int x, int y) { return x < y ? x : y; });
    st2.build(a, n, [&] (int x, int y) { return x > y ? x : y; });

    vector<int> pos = {0};
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        dp[i + 1] = -1;

        int lo = 0, hi = upper_bound(all(pos), i - l + 1) - pos.begin() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (st2.query(pos[mid], i) - st1.query(pos[mid], i) <= s)
                hi = mid;
            else lo = mid + 1;
        }

        if (st2.query(pos[lo], i) - st1.query(pos[lo], i) <= s and i - pos[lo] + 1 >= l)
            dp[i + 1] = 1 + dp[pos[lo]], pos.push_back(i + 1);
    }

    cout << dp[n] << "\n";
    return 0;
}