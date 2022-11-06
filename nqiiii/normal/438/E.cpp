#include <bits/stdc++.h>
using namespace std;
typedef long long Long;
namespace poly {
    const int mod = 998244353, g = 3;
    const int maxL = 800000;
    int len, rev[maxL + 10];

    int Add(int x, int y) {
        x += y; return x < mod ? x : x - mod;
    }
    int Dec(int x, int y) {
        x -= y; return x < 0 ? x + mod : x;
    }
    int Mul(int x, int y) {
        return 1ll * x * y % mod;
    }
    int Fpow(int x, Long y = mod - 2) {
        int ans = 1;
        while (y) {
            if (y & 1) ans = Mul(ans, x);
            y >>= 1; x = Mul(x, x);
        }
        return ans;
    }

    void PreWork(int n) {
        len = 1; int lgL = -1;
        while (len <= n) {
            len <<= 1; ++lgL;
        }
        for (int i = 0; i < len; ++i) {
            rev[i] = rev[i >> 1] >> 1 | (i & 1) << lgL;
        }
    }

    void Dft(int *a) {
        for (int i = 0; i < len; ++i)
            if (i < rev[i]) swap(a[i], a[rev[i]]);
        for (int i = 1; i < len; i <<= 1) {
            int wn = Fpow(g, (mod - 1) / (i << 1));
            for (int j = 0; j < len; j += i << 1)
                for (int k = 0, w = 1; k < i; ++k) {
                    int x = a[j + k], y = Mul(w, a[i + j + k]);
                    a[j + k] = Add(x, y); a[i + j + k] = Dec(x, y);
                    w = Mul(w, wn);
                }
        }
    }

    void IDft(int *a) {
        reverse(a + 1, a + len); Dft(a);
        int invL = Fpow(len); 
        for (int i = 0; i < len; ++i) a[i] = Mul(a[i], invL);
    }

    void PolyMul(int *a, int lenA, int *b, int lenB, int *res) {
        static int tmpA[maxL + 10], tmpB[maxL + 10];
        PreWork(lenA + lenB);
        for (int i = 0; i < len; ++i) {
            tmpA[i] = i <= lenA ? a[i] : 0;
            tmpB[i] = i <= lenB ? b[i] : 0;
        }
        Dft(tmpA); Dft(tmpB);
        for (int i = 0; i < len; ++i) res[i] = Mul(tmpA[i], tmpB[i]);
        IDft(res);
    }

    void PolyInv(int *a, int lenA, int *res) {
        // a != res !!!
        static int tmp[maxL + 10];
        if (!lenA) res[0] = Fpow(a[0]);
        else {
            PolyInv(a, lenA >> 1, res);
            PreWork(lenA << 1);
            for (int i = 0; i < len; ++i) {
                res[i] = i <= lenA >> 1 ? res[i] : 0;
                tmp[i] = i <= lenA? a[i] : 0;
            }
            Dft(res); Dft(tmp);
            for (int i = 0; i < len; ++i)
                res[i] = Mul(res[i], Dec(2, Mul(res[i], tmp[i])));
            IDft(res);
        }
    }

    void PolyLn(int *a, int lenA, int *res) {
        // a != res !!!
        static int tmp[maxL + 10];
        for (int i = 0; i <= lenA; ++i)
            tmp[i] = i == lenA ? 0 : Mul(a[i + 1], i + 1); 
        PolyInv(a, lenA, res);
        PolyMul(tmp, lenA, res, lenA, tmp);
        for (int i = 0; i <= lenA; ++i)
            res[i] = i == 0 ? 0 : Mul(tmp[i - 1], Fpow(i));
    }

    void PolyExp(int *a, int lenA, int *res) {
        // a != res !!!
        static int tmpA[maxL + 10], tmpB[maxL + 10];
        if (!lenA) res[0] = 1;
        else {
            PolyExp(a, lenA >> 1, res);
            for (int i = 0; i <= lenA; ++i)
                res[i] = i <= lenA >> 1 ? res[i] : 0;
            PolyLn(res, lenA, tmpB);
            PreWork(lenA << 1);
            for (int i = 0; i < len; ++i) {
                res[i] = i <= lenA >> 1 ? res[i] : 0;
                tmpA[i] = i <= lenA ? a[i] : 0;
                tmpB[i] = i <= lenA ? tmpB[i] : 0;
            }
            Dft(res); Dft(tmpA); Dft(tmpB);
            for (int i = 0; i < len; ++i)
                res[i] = Mul(res[i], Dec(Add(1, tmpA[i]), tmpB[i]));
            IDft(res);
        }
    }

    void PolySqrt(int *a, int lenA, int *res) {
        //a != res!!!
        static int tmpA[maxL + 10], tmpB[maxL + 10];
        if (!lenA) res[0] = 1;
        else {
            PolySqrt(a, lenA >> 1, res);
            for (int i = 0; i <= lenA; ++i)
                res[i] = i <= lenA >> 1 ? res[i] : 0;
            PolyInv(res, lenA, tmpB);
            PreWork(lenA << 1);
            for (int i = 0; i < len; ++i) {
                res[i] = i <= lenA >> 1 ? res[i] : 0;
                tmpA[i] = i <= lenA ? a[i] : 0;
                tmpB[i] = i <= lenA ? tmpB[i] : 0;
            }
            Dft(res); Dft(tmpA); Dft(tmpB);
            int inv2 = Fpow(2);
            for (int i = 0; i < len; ++i)
                res[i] = Mul(Add(tmpA[i], Mul(res[i], res[i])), Mul(tmpB[i], inv2));
            IDft(res);
        }
    }
};
using namespace poly;
int n, m;
int a[maxL + 10], res[maxL + 10];

int main() {
    scanf("%d%d", &n, &m);
    a[0] = 1;
    for (int i = 1; i <= n; ++i) {
        int x; scanf("%d", &x); a[x] -= 4;
    }
    PolySqrt(a, m, res); ++res[0];
    PolyInv(res, m, a);
    for (int i = 1; i <= m; ++i)
        printf("%d\n", Add(a[i], a[i]));
}