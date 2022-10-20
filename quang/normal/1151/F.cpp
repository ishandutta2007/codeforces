#include <bits/stdc++.h>

using namespace std;

const int N = 110;
const int MOD = 1000000007;

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

int n, k;
int a[N];

struct Matrix {
    int a[N / 2][N / 2];
    Matrix(int dia = 0) {
        memset(a, 0, sizeof a);
        for (int i = 0; i <= n / 2; i++) a[i][i] = dia;
    }

    Matrix operator * (const Matrix &u) {
        Matrix res;
        for (int k = 0; k <= n / 2; k++) {
            for (int i = 0; i <= n / 2; i++) {
                for (int j = 0; j <= n / 2; j++) {
                    res.a[i][j] = add(res.a[i][j], mul(a[i][k], u.a[k][j]));
                }
            }
        }
        return res;
    }

    Matrix operator ^ (int v) {
        Matrix res(1);
        Matrix u = *this;
        while (v) {
            if (v & 1) res = res * u;
            u = u * u;
            v >>= 1;
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    int cntZero = 0;
    int cntOne = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cntZero += (a[i] == 0);
        cntOne += (a[i] == 1);
    }
    int cnt = 0;
    for (int i = 1; i <= cntZero; i++) {
        cnt += (a[i] == 1);
    }
    Matrix base(0);
    for (int i = 0; i <= n / 2; i++) {
        int tot = n * (n - 1) / 2;
        int a = sub(cntZero, i);
        int b = sub(cntOne, i);
        int foo = mul(a, b);
        tot = sub(tot, foo);
        if (i + 1 <= n / 2) base.a[i][i + 1] = foo;
        foo = mul(i, i);
        tot = sub(tot, foo);
        if (i - 1 >= 0) base.a[i][i - 1] = foo;
        base.a[i][i] = tot;
    }
    Matrix a;
    a.a[0][cnt] = 1;
    base = base ^ k;
    a = a * base;
    int res = a.a[0][0];
    int bar = n * (n - 1) / 2;
    bar = power(bar, k);
    res = mul(res, inv(bar));
    cout << res << endl;
    return 0;
}