#include <bits/stdc++.h>

using namespace std;

template<int MOD>
struct Modular {
    int val;

    Modular(long long u = 0) {
        val = ((u % MOD) + MOD) % MOD;
    }

    Modular operator+(const Modular &o) const {
        int res = val + o.val;
        if (res >= MOD) res -= MOD;
        return {res};
    }

    Modular operator-(const Modular &o) const {
        int res = val - o.val;
        if (res < 0) res += MOD;
        return {res};
    }

    Modular operator*(const Modular &o) const {
        return {1ll * val * o.val % MOD};
    }

    Modular& operator+=(const Modular &o) {
        val += o.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }

    Modular& operator-=(const Modular &o) {
        val -= o.val;
        if (val < 0) val += MOD;
        return *this;
    }

    Modular& operator*=(const Modular &o) {
        val = 1ll * val * o.val % MOD;
        return *this;
    }

    Modular power(int v) const {
        Modular u = *this;
        Modular res = 1;
        while (v) {
            if (v & 1) res *= u;
            u *= u;
            v >>= 1;
        }
        return res;
    }

    Modular inv() {
        return {this->power(MOD - 2)};
    }
};

template <int MOD>
ostream& operator<<(ostream& os, const Modular<MOD>& m) {
    return os << m.val;
}

constexpr int MOD = 998244353;
using Mint = Modular<MOD>;

const int N = 3010;

int n, m;
char s[N], t[N];
Mint dp[N][N];
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> (s + 1);
    cin >> (t + 1);
    n = strlen(s + 1);
    m = strlen(t + 1);
    for (int i = 1; i <= m + 1; i++) {
        dp[0][i] = 1;
    }
    Mint res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i] == t[j]) {
                dp[i][j] += dp[i - 1][j + 1];
            }
            if (j + i - 1 > m || s[i] == t[j + i - 1]) {
                dp[i][j] += dp[i - 1][j];
            }
        }
        dp[i][m + 1] = dp[i - 1][m + 1] * 2;
        if (i >= m) {
            res += dp[i][1];
        }
    }
    cout << res << endl;
    return 0;
}