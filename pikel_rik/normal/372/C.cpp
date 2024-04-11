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
const int M = 300 + 1;
const int N = 150000;

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

int n, m, d, a[M], b[M], t[M];
ll dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> d;
    for (int i = 0; i < m; i++) cin >> a[i] >> b[i] >> t[i], --a[i];

    for (int i = 0; i < n; i++) {
        dp[i] = b[0] - abs(a[0] - i);
    }

    SparseTable<ll> st;
    for (int i = 1; i < m; i++) {
        st.build(dp, n, [&] (ll x, ll y) {
            return max(x, y);
        });

        for (int j = 0; j < n; j++) {
            int l = max(0ll, j - (t[i] - t[i - 1]) * (ll)d), r = min(n - 1ll, j + (t[i] - t[i - 1]) * (ll)d);
            dp[j] = b[i] - abs(a[i] - j) + st.query(l, r);
        }
    }

    cout << *max_element(dp, dp + n) << "\n";
    return 0;
}