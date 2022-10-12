#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MOD = 1000000007;

struct Matrix {
    static const int SZ = 2;
    LL a[SZ][SZ];
    
    Matrix (LL _a = 0) {
        for (int i=0; i<SZ; i++) {
            for (int j=0; j<SZ; j++) a[i][j] = 0;
            a[i][i] = _a;
        }
    }
    
    Matrix operator * (const Matrix &other) const {
        Matrix ret;
        for (int i=0; i<SZ; i++)
            for (int j=0; j<SZ; j++)
                for (int k=0; k<SZ; k++)
                    ret.a[i][j] += a[i][k] * other.a[k][j],
                    ret.a[i][j] %= MOD;
                    
        return ret;
    }    
};

Matrix power (Matrix x, LL y) {
    Matrix ret = Matrix(1);
    Matrix mul = x;
    while (y) {
        if (y & 1) ret = ret * mul;
        mul = mul * mul;
        y >>= 1;
    }
    
    return ret;
}

LL power (LL x, LL y) {
    LL ret = 1;
    LL mul = x;
    while (y) {
        if (y & 1) ret = ret * mul % MOD;
        mul = mul * mul % MOD;
        y >>= 1;
    }
    
    return ret;
}

int main() {
    int k;
    scanf ("%d", &k);
    
    LL a[k];
    for (int i=0; i<k; i++) scanf ("%I64d", a + i);
        
    Matrix DP;
    DP.a[0][0] = 1, DP.a[0][1] = 1; DP.a[1][0] = 2, DP.a[1][1] = 0;
    
    LL q = 2;
    for (int i=0; i<k; i++) {
        DP = power(DP, a[i]);
        q = power(q, a[i]);
    }
    
    LL p = DP.a[1][1];
    p = p * 500000004 % MOD;
    q = q * 500000004 % MOD;
    
    printf ("%lld/%lld\n", p, q);
    
    return 0;
}