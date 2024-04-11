#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;

template <typename T>
class SparseTable2D {
public:
    using F = function<T(const T&, const T&)>;

    int n, m;
    vector<vector<vector<vector<T>>>> mat;
    F f;

    template <typename U>
    SparseTable2D(const U& arr, int n, int m, F f): n(n), m(m), f(f), mat((int)log2(n) + 1, vector<vector<vector<T>>>((int)log2(m) + 1)) {
        mat[0][0].assign(n, vector<T>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mat[0][0][i][j] = T(arr[i + 1][j + 1]);
            }
        }

        for (int k = 1; k < mat.size(); k++) {
            mat[k][0].assign(n - (1 << k) + 1, vector<T>(m));
            for (int i = 0; i + (1 << k) <= n; i++) {
                for (int j = 0; j < m; j++) {
                    mat[k][0][i][j] = f(mat[k - 1][0][i][j], mat[k - 1][0][i + (1 << (k - 1))][j]);
                }
            }
        }

        for (int k = 1; k < mat[0].size(); k++) {
            mat[0][k].assign(n , vector<T>(m - (1 << k) + 1));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j + (1 << k) <= m; j++) {
                    mat[0][k][i][j] = f(mat[0][k - 1][i][j], mat[0][k - 1][i][j + (1 << (k - 1))]);
                }
            }
        }

        for (int p1 = 1; p1 < mat.size(); p1++) {
            for (int p2 = 1; p2 < mat[0].size(); p2++) {
                mat[p1][p2].assign(n - (1 << p1) + 1, vector<T>(m - (1 << p2) + 1));
                for (int i = 0; i + (1 << p1) <= n; i++) {
                    for (int j = 0; j + (1 << p2) <= m; j++) {
                        mat[p1][p2][i][j] = f(mat[p1][p2 - 1][i][j], mat[p1][p2 - 1][i][j + (1 << (p2 - 1))]);
                    }
                }
            }
        }
    }

    T query(int x1, int y1, int x2, int y2) {
        int i = 32 - __builtin_clz(x2 - x1 + 1) - 1, j = 32 - __builtin_clz(y2 - y1 + 1) - 1;
        T res1 = f(mat[i][j][x1][y1], mat[i][j][x2 + 1 - (1 << i)][y1]);
        T res2 = f(mat[i][j][x1][y2 + 1 - (1 << j)], mat[i][j][x2 + 1 - (1 << i)][y2 + 1 - (1 << j)]);
        return f(res1, res2);
    }
};

const int N = 500 + 5;

int n, m, q, a[N][N];
int dp[4][N][N], dpfinal[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++) { //red = 0, green = 1, yelow = 3, blu = 2
            a[i][j] = (s[j - 1] == 'R' ? 0 : (s[j - 1] == 'G' ? 1 : (s[j - 1] == 'B' ? 2 : 3)));
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 0) {
                dp[0][i][j] = 1 + min({dp[0][i - 1][j], dp[0][i][j - 1], dp[0][i - 1][j - 1]});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            if (a[i][j] == 1) {
                dp[1][i][j] = 1 + min({dp[1][i - 1][j], dp[1][i][j + 1], dp[1][i - 1][j + 1]});
            }
        }
    }

    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            if (a[i][j] == 2) {
                dp[2][i][j] = 1 + min({dp[2][i + 1][j], dp[2][i][j + 1], dp[2][i + 1][j + 1]});
            }
        }
    }

    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 3) {
                dp[3][i][j] = 1 + min({dp[3][i + 1][j], dp[3][i][j - 1], dp[3][i + 1][j - 1]});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int len = min({dp[0][i][j], dp[1][i][j + 1], dp[2][i + 1][j + 1], dp[3][i + 1][j]});
            dpfinal[i][j] = len;
        }
    }

    SparseTable2D<int> st(dpfinal, n, m, [&] (int x, int y) {
        return x > y ? x : y;
    });

    while (q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        --r1; --c1; --r2; --c2;

        int lo = 0, hi = min(r2 - r1 + 1, c2 - c1 + 1) / 2; //1, 0, 4, 9
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (st.query(r1 + mid - 1, c1 + mid - 1, r2 - mid, c2 - mid) >= mid) //2, 1, 2, 7
                lo = mid;
            else hi = mid - 1;
        }
        cout << 4 * lo * lo << '\n';
    }
    return 0;
}