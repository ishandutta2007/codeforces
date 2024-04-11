#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int N = 200010;
const int M = 60;

inline int add(int u, int v) {
    return (u += v) >= MOD ? u - MOD : u;
}

inline int sub(int u, int v) {
    return (u -= v) < 0 ? u + MOD : u;
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

int n, m;
long long basis[M];
int k = 0;
int p[M];
int c[M][M];
int num[M][M];

int add(long long u) {
    for (int i = m - 1; i >= 0; i--) {
        if (u >> i & 1) {
            if (basis[i]) u ^= basis[i];
            else {
                basis[i] = u;
                k++;
                return 1;
            } 
        }
    }
    return 0;
}

void go(int u, long long mask, int m) {
    if (u == m) {
        int numBit = __builtin_popcountll(mask);
        p[numBit] = add(p[numBit], 1);
        return;
    }
    go(u + 1, mask, m);
    if (basis[u]) go(u + 1, mask ^ basis[u], m);
}

int getComb(int n, int k) {
    if (k < 0 || k > n) return 0;
    return c[n][k];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    int ways = 1;
    for (int i = 1; i <= n; i++) {
        long long u;
        cin >> u;
        if (!add(u)) {
            ways = mul(ways, 2);
        }
    }
    if (k <= 27) {
        go(0, 0, m);
        for (int i = 0; i <= m; i++) {
            cout << mul(p[i], ways) << ' ';
        }
        cout << endl;
    } else {
        // orthogonalize
        for (int i = m - 1; i >= 0; i--) {
            if (!basis[i]) continue;
            for (int j = m - 1; j > i; j--) {
                if (!basis[j]) continue;
                if (basis[j] >> i & 1) basis[j] ^= basis[i];
            }
        }


        // move all key bit to the most significant bits
        int cur = m - 1;
        for (int i = m - 1; i >= 0; i--) {
            if (basis[i]) {
                for (int j = m - 1; j >= 0; j--) {
                    long long u = (basis[j] >> i & 1);
                    long long v = (basis[j] >> cur & 1);
                    basis[j] ^= (u << i) ^ (v << i) ^ (u << cur) ^ (v << cur);
                }
                swap(basis[i], basis[cur]);
                cur--;
            }
        }

        for (int i = 0; i < m - k; i++) {
            basis[i] ^= (1ll << i);
            for (int j = m - k; j < m; j++) {
                basis[i] ^= ((basis[j] >> i & 1ll) << j);
            }
        }

        go(0, 0, m - k);

        // init conbination
        for (int i = 0; i < M; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) c[i][j] = 1;
                else c[i][j] = add(c[i - 1][j], c[i - 1][j - 1]);
            }
        }

        // init FWT_c of 2^i - 1
        for (int c = 0; c <= m; c++) {
            for (int j = 0; j <= m; j++) {
                for (int x = 0; x <= j; x++) {
                    int now = mul(getComb(j, x), getComb(m - j, c - x));
                    if (x & 1) num[c][j] = sub(num[c][j], now);
                    else num[c][j] = add(num[c][j], now);
                }
            }
        }

        int inv2 = inv(2);
        for (int i = 1; i <= m - k; i++) {
            ways = mul(ways, inv2);
        }

        for (int c = 0; c <= m; c++) {
            int res = 0;
            for (int i = 0; i <= m; i++) {
                res = add(res, mul(p[i], num[c][i]));
            }
            cout << mul(ways, res) << ' ';
        }
        cout << endl;
    }
    return 0;
}