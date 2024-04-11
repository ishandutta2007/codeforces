#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

#ifndef local
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

using namespace std;
using ll = long long;

struct IO {
    static const int SZ = 1 << 17;
    char inBuf[SZ], *in1, *in2;
    inline __attribute((always_inline))
    int read() {
        if(__builtin_expect(in1 > inBuf + SZ - 32, 0)) {
            auto len = in2 - in1;
            memcpy(inBuf, in1, len);
            in1 = inBuf, in2 = inBuf + len;
            in2 += fread(in2, 1, SZ - len, stdin);
            if(in2 != inBuf + SZ) *in2 = 0;
        }
        int res = 0;
        char c;
        while((c = *in1++) < 48);
        while(res = res * 10 + c - 48, (c = *in1++) >= 48);
        return res;
    }
    char outBuf[SZ], *out;
    inline __attribute((always_inline))
    void write(double x0) {
        if(__builtin_expect(out > outBuf + SZ - 32, 0))
            fwrite(outBuf, 1, out - outBuf, stdout), out = outBuf;
        ll x = x0, y = (x0 - x) * 1e10;
        alignas(2) const char* digits =
        "0001020304050607080910111213141516171819"
        "2021222324252627282930313233343536373839"
        "4041424344454647484950515253545556575859"
        "6061626364656667686970717273747576777879"
        "8081828384858687888990919293949596979899";
        alignas(2) static char buf[30];
        char* p = buf + 30;
        *--p = '\n';
        for(int i = 5; i; i--) memcpy(p -= 2, digits + y % 100 * 2, 2), y /= 100;
        *--p = '.';
        if(x) {
            while(x >= 10) memcpy(p -= 2, digits + x % 100 * 2, 2), x /= 100;
            if(x) *--p = 48 + x;
        } else *--p = '0';
        auto len = buf + 30 - p;
        memcpy(out, p, len), out += len;
    }
    IO() {
        in1 = inBuf;
        in2 = in1 + fread(in1, 1, SZ, stdin);
        out = outBuf;
    }
    ~IO() { fwrite(outBuf, 1, out - outBuf, stdout); }
} IO;

const int N = 2e5 + 8, M = 1 << 18;

int n, q, x, y;
double c[M << 1][3][3];

inline void mul(double c[3][3], double a[3][3], double b[3][3]) {
    #pragma GCC unroll 64
    rep(i, 0, 2)
    #pragma GCC unroll 64
    rep(j, 0, 2) c[i][j] = max({a[i][0] + b[0][j], a[i][1] + b[1][j], a[i][2] + b[2][j]});
}
int main() {
    n = IO.read(), q = IO.read(), x = IO.read(), y = IO.read();
    double v1 = 1.0 / (x + y), v2 = 1.0 / max(x, y);
    rep(i, M + 1, M + n) {
        int k = IO.read();
        c[i][0][1] = c[i][1][1] = v1 * k;
        c[i][0][2] = v2 * k;
    }
    per(i, M - 1, 1) mul(c[i], c[i << 1], c[i << 1 | 1]);
    while(q--) {
        int t = IO.read(), a = IO.read(), b = IO.read();
        if(t == 1) {
            a += M;
            c[a][0][1] = c[a][1][1] = v1 * b;
            c[a][0][2] = v2 * b;
            while(a > 1) a >>= 1, mul(c[a], c[a << 1], c[a << 1 | 1]);
        } else {
            double L[3][3] = {}, R[3][3] = {}, t[3][3];
            for(a += M - 1, b += M + 1; a ^ b ^ 1; a >>= 1, b >>= 1) {
                if(~a & 1) mul(t, L, c[a ^ 1]), memcpy(L, t, sizeof t);
                if(b & 1) mul(t, c[b ^ 1], R), memcpy(R, t, sizeof t);
            }
            mul(t, L, R), IO.write(max({t[0][0], t[0][1], t[0][2]}));
        }
    }
}