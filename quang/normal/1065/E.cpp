#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const int MOD = 998244353;

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


int n, m, a;
int b[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> a;
    a %= MOD;
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    b[0] = 0;
    int inv2 = inv(2);
    int res = power(a, n - 2 * b[m]);
    for (int i = 1; i <= m; i++) {
        int foo = power(a, b[i] - b[i - 1]);
        foo = mul(foo, add(foo, 1));
        foo = mul(foo, inv2);
        res = mul(res, foo);
    }
    cout << res << endl;
    return 0;
}