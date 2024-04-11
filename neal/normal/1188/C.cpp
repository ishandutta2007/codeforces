#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

struct mod_int {
    int val;

    mod_int(long long v = 0) {
        if (v < 0)
            v = v % MOD + MOD;

        if (v >= MOD)
            v %= MOD;

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

    mod_int& operator*=(const mod_int &other) {
        val = (uint64_t) val * other.val % MOD;
        return *this;
    }

    mod_int& operator/=(const mod_int &other) {
        return *this *= other.inv();
    }

    friend mod_int operator+(const mod_int &a, const mod_int &b) {
        return mod_int(a) += b;
    }

    friend mod_int operator-(const mod_int &a, const mod_int &b) {
        return mod_int(a) -= b;
    }

    friend mod_int operator*(const mod_int &a, const mod_int &b) {
        return mod_int(a) *= b;
    }

    friend mod_int operator/(const mod_int &a, const mod_int &b) {
        return mod_int(a) /= b;
    }

    mod_int& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }

    mod_int operator++(int) {
        mod_int before = *this;
        ++*this;
        return before;
    }

    mod_int& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }

    mod_int operator--(int) {
        mod_int before = *this;
        --*this;
        return before;
    }

    mod_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }

    bool operator==(const mod_int &other) const {
        return val == other.val;
    }

    bool operator!=(const mod_int &other) const {
        return val != other.val;
    }

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
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> A(N);

    for (int &a : A)
        cin >> a;

    sort(A.begin(), A.end());
    int range = A.back() - A.front();
    mod_int total = 0;

    vector<mod_int> dp(N + 1), dp_sum(N + 1);

    for (int diff = 1; range / diff + 1 >= K; diff++) {
        for (int i = 0; i <= N; i++) {
            dp[i] = 1;
            dp_sum[i] = i;
        }

        for (int k = 0; k < K - 1; k++) {
            for (int i = 0, j = 0; i < N; i++) {
                while (A[i] - A[j] >= diff)
                    j++;

                dp[i] = dp_sum[j];
            }

            dp_sum[0] = 0;

            for (int i = 0; i < N; i++)
                dp_sum[i + 1] = dp_sum[i] + dp[i];
        }

        total += dp_sum[N];
    }

    cout << (int) total << '\n';
}