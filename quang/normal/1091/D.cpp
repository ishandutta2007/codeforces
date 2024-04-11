#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;
const int MOD = 998244353;

inline int add(int u, int v) {
    u += v;
    if (u >= MOD) u -= MOD;
    return u;
}

inline int sub(int u, int v) {
    u -= v;
    if (u < 0) u += MOD;
    return u;
}

inline int mul(int u, int v) {
    return (long long)u * v % MOD;
}

inline int power(int u, int v) {
    int res = 1;
    while (v) {
        if (v & 1) res = mul(res, u);
        u = mul(u, u);
        v >>= 1;
    }
    return res;
}
inline int inv(int u) {
    return power(u, MOD - 2);
}

int n;
int f[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = mul(f[i - 1], i);
    }
    int res = f[n];
    for (int i = 1; i < n; i++) {
        int foo = mul(f[n], inv(f[n - i]));
        int bar = sub(f[n - i], 1);
        res = add(res, mul(foo, bar));
    }
    cout << res << endl;
    return 0;
}