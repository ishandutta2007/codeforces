#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

struct mod_int {
    int val;

    mod_int(long long v = 0) {
        if (v < 0) v = v % MOD + MOD;
        if (v >= MOD) v %= MOD;
        val = v;
    }

    static int mod_inv(int a, int m = MOD) {
        // https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Example
        int g = m, r = a, x = 0, y = 1;

        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }

        return x < 0 ? x + m : x;
    }

    explicit operator int() const {
        return val;
    }

    mod_int& operator+=(const mod_int &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }

    mod_int& operator-=(const mod_int &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }

    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
        return x % m;
#endif
        // Optimized mod for Codeforces 32-bit machines.
        // x must be less than 2^32 * m for this to work, so that x / m fits in a 32-bit integer.
        unsigned x_high = x >> 32, x_low = (unsigned) x;
        unsigned quot, rem;
        asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }

    mod_int& operator*=(const mod_int &other) {
        val = fast_mod((uint64_t) val * other.val);
        return *this;
    }

    mod_int& operator/=(const mod_int &other) {
        return *this *= other.inv();
    }

    friend mod_int operator+(const mod_int &a, const mod_int &b) { return mod_int(a) += b; }
    friend mod_int operator-(const mod_int &a, const mod_int &b) { return mod_int(a) -= b; }
    friend mod_int operator*(const mod_int &a, const mod_int &b) { return mod_int(a) *= b; }
    friend mod_int operator/(const mod_int &a, const mod_int &b) { return mod_int(a) /= b; }

    mod_int& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }

    mod_int& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }

    mod_int operator++(int) { mod_int before = *this; ++*this; return before; }
    mod_int operator--(int) { mod_int before = *this; --*this; return before; }

    mod_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }

    bool operator==(const mod_int &other) const { return val == other.val; }
    bool operator!=(const mod_int &other) const { return val != other.val; }

    mod_int inv() const {
        return mod_inv(val);
    }

    mod_int pow(long long p) const {
        assert(p >= 0);
        mod_int a = *this, result = 1;

        while (p > 0) {
            if (p & 1)
                result *= a;

            a *= a;
            p >>= 1;
        }

        return result;
    }

    friend ostream& operator<<(ostream &stream, const mod_int &m) {
        return stream << m.val;
    }
};


const int NM_MAX = 2005;

int N, M;
vector<string> grid;
int row_count[NM_MAX][NM_MAX];
int col_count[NM_MAX][NM_MAX];

mod_int dp_down[NM_MAX][NM_MAX];
mod_int dp_right[NM_MAX][NM_MAX];
mod_int dp_right_sum[NM_MAX][NM_MAX];
mod_int dp_down_sum[NM_MAX][NM_MAX];

int get_row_count(int r, int c_start, int c_end) {
    return row_count[r][c_end] - row_count[r][c_start];
}

int get_col_count(int c, int r_start, int r_end) {
    return col_count[r_end][c] - col_count[r_start][c];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    grid.resize(N);

    for (string &row : grid)
        cin >> row;

    if (N == 1 && M == 1) {
        cout << 1 << '\n';
        return 0;
    }

    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++) {
            int here = grid[r][c] == 'R';
            row_count[r][c + 1] = row_count[r][c] + here;
            col_count[r + 1][c] = col_count[r][c] + here;
        }

    dp_down[0][0] = dp_right[0][0] = 1;

    for (int r = 0; r < N; r++)
        for (int c = 0; c < M; c++) {
            if (r == 0 && c == 0)
                goto finish;

            // cerr << r << ' ' << c << ": " << get_col_count(c, r, N) << endl;

            if (r == 0 || get_col_count(c, r, N) == N - r) {
                // cerr << "setting dp_down[" << r << "][" << c << "] = 0" << endl;
                dp_down[r][c] = 0;
            } else {
                int low = 0, high = r - 1;

                while (low < high) {
                    int mid = (low + high) / 2;

                    if (get_col_count(c, mid + 1, N) < N - r)
                        high = mid;
                    else
                        low = mid + 1;
                }

                // dp_down[r][c] = sum of dp_right[low][c] through dp_right[r - 1][c]
                dp_down[r][c] = dp_right_sum[r][c] - dp_right_sum[low][c];
            }

            if (c == 0 || get_row_count(r, c, M) == M - c) {
                dp_right[r][c] = 0;
            } else {
                int low = 0, high = c - 1;

                while (low < high) {
                    int mid = (low + high) / 2;

                    if (get_row_count(r, mid + 1, M) < M - c)
                        high = mid;
                    else
                        low = mid + 1;
                }

                // dp_right[r][c] = sum of dp_down[r][low] through dp_down[r][c - 1]
                dp_right[r][c] = dp_down_sum[r][c] - dp_down_sum[r][low];
            }

            finish:
            dp_right_sum[r + 1][c] = dp_right_sum[r][c] + dp_right[r][c];
            dp_down_sum[r][c + 1] = dp_down_sum[r][c] + dp_down[r][c];

            // cerr << r << ' ' << c << ": " << dp_down[r][c] << " (down) " << dp_right[r][c] << " (right)" << endl;
        }

    mod_int answer = dp_right[N - 1][M - 1] + dp_down[N - 1][M - 1];
    cout << answer << '\n';
}