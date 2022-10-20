#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;
const int MOD = 1000000007;

inline int add(int u, int v) {
    u += v;
    if (u >= MOD) {
        u -= MOD;
    }
    return u;
}

inline int sub(int u, int v) {
    u -= v;
    if (u < 0) {
        u += MOD;
    }
    return u;
}

inline int mul(int u, int v) {
    return (long long)u * v % MOD;
}

inline int power(int u, int v) {
    if (v == -1) return power(u, MOD - 2);
    int res = 1;
    while (v) {
        if (v & 1) {
            res = mul(res, u);
        }
        u = mul(u, u);
        v >>= 1;
    }
    return res;
}

inline int inv(int u) {
    return power(u, MOD - 2);
}

int n, m;
int f[N], invF[N];

void init() {
    f[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = mul(f[i - 1], i);
    }
    invF[N - 1] = inv(f[N - 1]);
    for (int i = N - 2; i >= 0; i--) {
        invF[i] = mul(invF[i + 1], i + 1);
    }
}

int c(int n, int k) {
    if (k < 0 || k > n) return 0;
    return mul(f[n], mul(invF[k], invF[n - k]));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int foo, bar;
    cin >> n >> m >> foo >> bar;
    init();

    int res = 0;
    for (int i = 0; i <= n - 2; i++) {
        int ways = c(m - 1, i);
        ways = mul(ways, c(n - 2, i));
        ways = mul(ways, f[i]);
        int forest = mul(i + 2, power(n, n - (i + 2) - 1));
        ways = mul(ways, forest);
        int edges = n - 1 - (i + 1);
        ways = mul(ways, power(m, edges));
        res = add(res, ways);
    }
    cout << res << endl;
    return 0;
}