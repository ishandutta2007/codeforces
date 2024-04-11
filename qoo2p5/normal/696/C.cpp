#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int MOD = 1e9 + 7;

int mod(int x) {
    if (x >= MOD) {
        return x - MOD;
    }
    if (x < 0) {
        return x + MOD;
    }
    return x;
}

int power(int a, int p) {
    if (p == 0) {
        return 1;
    }
    
    if (p & 1) {
        return (a * 1LL * power(a, p - 1)) % MOD;
    }
    
    int tmp = power(a, p / 2);
    return (tmp * 1LL * tmp) % MOD;
}

struct Matrix {
    int n, m;
    int a[2][2];
    
    Matrix(int n, int m) : n(n), m(m) {
        for (int i = 0; i < n; i++) {
            fill(a[i], a[i] + m, 0);
        }
    }
    
    int *operator[](int i) {
        return a[i];
    }
    
    Matrix operator*(Matrix &b) {
        Matrix res(n, b.m);
        
        for (int i = 0; i < res.n; i++) {
            for (int j = 0; j < res.m; j++) {
                for (int k = 0; k < m; k++) {
                    res[i][j] = mod(res[i][j] + (a[i][k] * 1LL * b[k][j]) % MOD);
                }
            }
        }
        
        return res;
    }
};

void mult(Matrix &a, Matrix &b, Matrix &res) {
    for (int i = 0; i < res.n; i++) {
        for (int j = 0; j < res.m; j++) {
            res[i][j] = 0;
            for (int k = 0; k < a.m; k++) {
                res[i][j] = mod(res[i][j] + (a[i][k] * 1LL * b[k][j]) % MOD);
            }
        }
    }
}

Matrix power(Matrix &a, ll p) {
    int start = -1;
    
    for (int i = 62; i >= 0; i--) {
        if (p & (1LL << i)) {
            start = i;
            break;
        }
    }
    
    assert(start != -1);
    Matrix ans = a;
    Matrix tmp = ans;
    
    for (int i = start - 1; i >= 0; i--) {
        mult(ans, ans, tmp);
        ans = tmp;
        
        if (p & (1LL << i)) {
            mult(ans, a, tmp);
            ans = tmp;
        }
    }
    
    return ans;
}

int main() {
    Matrix go(2, 2);
    go[0][0] = -1;
    go[0][1] = 0;
    go[1][0] = 1;
    go[1][1] = 2;
    
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        ll k;
        scanf("%lld", &k);
        go = power(go, k);
    }
        
    Matrix init(1, 2);
    init[0][0] = 0;
    init[0][1] = 1;
    
    Matrix ans = init * go;
        
    int na = ans[0][0];
    int np = ans[0][1];
    
    int p = (np * 1LL * power(2, MOD - 2)) % MOD;
    int a = mod(p - na);
    
    printf("%d/%d\n", a, p);
    
    return 0;
}