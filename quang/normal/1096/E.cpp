#include <bits/stdc++.h>

using namespace std;

const int P = 110;
const int N = 5500;
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

int p, s, r;
int c[N][N];

void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == i || j == 0) c[i][j] = 1;
            else c[i][j] = add(c[i - 1][j], c[i - 1][j - 1]);
        }
    }
}

int getC(int n, int k) {
    if (n < 0) return 0;
    if (k > n || k < 0) return 0;
    return c[n][k];
}

int get(int n, int sum, int lim) {
    if (n == 0) {
        if (sum == 0) return 1;
        else return 0;
    }
    int res = 0;
    for (int i = 0; i <= n; i++) {
        int sumNow = sum - lim * i;
        if (sumNow < 0) break;
        int foo = getC(n, i);
        foo = mul(foo, getC(sumNow + n - 1, n - 1));
        if (i & 1) {
            res = sub(res, foo);
        } else {
            res = add(res, foo);
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> p >> s >> r;
    init();
    int tot = getC(s - r + p - 1, p - 1);
    int res = 0;
    for (int i = r; i <= s; i++) {
        for (int j = 1; j * i <= s && j <= p; j++) {
            int foo = get(p - j, s - i * j, i);
            foo = mul(foo, getC(p - 1, j - 1));
            res = add(res, mul(foo, inv(j)));
        }
    }
    cout << mul(res, inv(tot)) << endl;
    return 0;
}