#include <bits/stdc++.h>

using namespace std;

const int M = 4;
const int K = 13;
const int N = K * (1 << M) + 1;
const int MOD = 1000000007;

inline int add(int u, int v) {
    return (u += v) >= MOD ? u - MOD : u;
}

inline int sub(int u, int v) {
    return (u -= v) < 0 ? u + MOD : u;
}

inline int mul(int u, int v) {
    return (long long)u * v % MOD;
}

struct Matrix {
    int a[N][N];

    Matrix(int diag = 0) {
        memset(a, 0, sizeof a);
        for (int i = 0; i < N; i++) a[i][i] = diag;
    }

    int* operator [] (int u) {
        return a[u];
    }

    Matrix operator * (Matrix &u) const {
        Matrix res;
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) if (a[i][k]) {
                for (int j = 0; j < N; j++) {
                    res[i][j] = add(res[i][j], mul(a[i][k], u[k][j]));
                }
            }
        }
        return res;
    }

    Matrix operator ^ (int v) const {
        Matrix res(1);
        Matrix u = *this;
        while (v) {
            if (v & 1) res = res * u;
            u = u * u;
            v >>= 1;
        }
        return res;
    }

    void debug(int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cout << a[i][j];
            cout << endl;
        }
        cout << endl;
    }
};

int n, m, k;

int encode(int u, int mask) {
    return (u << m) + mask;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> m;
    Matrix b;
    for (int i = 0; i <= k; i++) {
        for (int mask = 0; mask < (1 << m); mask++) {
            int id = encode(i, mask);
            int id2 = encode(i, (mask << 1) & ((1 << m) - 1));
            b[id][id2] = 1;
            if (i < k) {
                id2 = encode(i + 1, (mask << 1) & ((1 << m) - 1) | 1);
                b[id][id2] = __builtin_popcount(mask) + 1;
            }
        }
    }
    Matrix a;
    a[0][0] = 1;
    // b.debug((k + 1) << m);
    Matrix c = b ^ n;
    // c.debug((k + 1) << m);
    c = a * c;
    // c.debug((k + 1) << m);
    int res = 0;
    for (int mask = 0; mask < (1 << m); mask++) {
        res = add(res, c[0][encode(k, mask)]);
    }
    cout << res << endl;
    return 0;
}