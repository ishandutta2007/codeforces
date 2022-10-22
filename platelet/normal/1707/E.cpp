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

struct precalc {
    alignas(64) char digit[40000];
    uint64_t log[64][2];
    constexpr precalc() : digit{}, log{} {
        for(int i = 0; i < 10000; i++) {
            digit[i * 4 + 0] = 48 + i / 1000;
            digit[i * 4 + 1] = 48 + i / 100 % 10;
            digit[i * 4 + 2] = 48 + i / 10 % 10;
            digit[i * 4 + 3] = 48 + i % 10;
        }
        int index = 0;
        uint64_t value = 9;
        for(int i = 0; i < 64; i++) {
            // [2^i-1, 2^(i+1)-2]
            log[i][0] = index, log[i][1] = value;
            if((2ULL << i) - 2 > value)
                index++, value = value <= (UINT64_MAX - 9) / 10 ? value * 10 + 9 : UINT64_MAX;
        }
    }
    inline __attribute((always_inline))
    void store(void* out, uint64_t k)const {
        memcpy(out, digit + k * 4, 4);
    }
};
struct IO {
    static const int inSZ = 1 << 17;
    char inBuf[inSZ], *in1, *in2;
    inline __attribute((always_inline))
    int read() {
        if(in1 > inBuf + inSZ - 32) [[unlikely]] {
            auto len = in2 - in1;
            memcpy(inBuf, in1, len);
            in1 = inBuf, in2 = inBuf + len;
            in2 += fread(in2, 1, inSZ - len, stdin);
            if(in2 != inBuf + inSZ) *in2 = 0;
        }
        int res = 0;
        char c;
        while((c = *in1++) < 48);
        while(res = res * 10 + c - 48, (c = *in1++) >= 48);
        return res;
    }
    static const int outSZ = 1 << 21;
    char outBuf[outSZ], *out;
    inline __attribute((always_inline))
    void write(uint64_t x) {
        if(__builtin_expect(out > outBuf + outSZ - 32, 0))
            fwrite(outBuf, 1, out - outBuf, stdout), out = outBuf;
        static constexpr auto P = precalc();
        uint64_t bsr = __builtin_clzll(x + 1) ^ 63;
        const uint64_t B = 10000, B2 = B * B, B3 = B2 * B, B4 = B3 * B;
        uint64_t len = P.log[bsr][0] + (P.log[bsr][1] < x);
        const uint64_t extra[4] = {1000, 100, 10, 1};
        x *= extra[len & 3];
        switch(len >> 2) {
            case 0: // [0, 9999]
                P.store(out, x);
                break;
            case 1: // [10000, 99999999]
                P.store(out + 4, x - x / B * B);
                P.store(out, x / B);
                break;
            case 2:
                P.store(out + 8, x - x / B * B);
                P.store(out + 4, x / B - x / B2 * B);
                P.store(out, x / B2);
                break;
            case 3:
                P.store(out + 12, x - x / B * B);
                P.store(out + 8, x / B - x / B2 * B);
                P.store(out + 4, x / B2 - x / B3 * B);
                P.store(out, x / B3);
                break;
            case 4:
                P.store(out + 16, x - x / B * B);
                P.store(out + 12, x / B - x / B2 * B);
                P.store(out + 8, x / B2 - x / B3 * B);
                P.store(out + 4, x / B3 - x / B4 * B);
                P.store(out, x / B4);
                break;
        }
        out += len + 2, out[-1] = '\n';
    }
    IO() {
        in1 = inBuf;
        in2 = in1 + fread(in1, 1, inSZ, stdin);
        out = outBuf;
    }
    ~IO() { fwrite(outBuf, 1, out - outBuf, stdout); }
} IO;

const int N = 1e5 + 8;

int n, q, a[N], f[18][N][2], g[17][N][2], L[N], R[N], ans[N];

int main() {
    n = IO.read(), q = IO.read();
    rep(i, 1, n) a[i] = IO.read(), f[0][i][0] = min(a[i], a[i - 1]), f[0][i][1] = max(a[i], a[i - 1]);
    rep(i, 1, q) L[i] = IO.read(), R[i] = IO.read();
    rep(i, 1, 17) {
        rep(j, 2, n) g[0][j][0] = f[i - 1][j][0], g[0][j][1] = f[i - 1][j][1];
        rep(j, 1, 16) rep(k, 1 << j, n) {
            g[j][k][0] = min(g[j - 1][k][0], g[j - 1][k - (1 << j - 1)][0]);
            g[j][k][1] = max(g[j - 1][k][1], g[j - 1][k - (1 << j - 1)][1]);
        }
        rep(j, 2, n) {
            int L = f[i - 1][j][0], R = f[i - 1][j][1];
            if(L >= R) f[i][j][0] = INT_MAX, f[i][j][1] = 0;
            else {
                int z = __builtin_clz(R - L) ^ 31;
                f[i][j][0] = min(g[z][R][0], g[z][L + (1 << z)][0]);
                f[i][j][1] = max(g[z][R][1], g[z][L + (1 << z)][1]);
            }
        }
    }
    per(i, 17, 0) {
        rep(j, 2, n) g[0][j][0] = f[i][j][0], g[0][j][1] = f[i][j][1];
        rep(j, 1, 16) rep(k, 1 << j, n) {
            g[j][k][0] = min(g[j - 1][k][0], g[j - 1][k - (1 << j - 1)][0]);
            g[j][k][1] = max(g[j - 1][k][1], g[j - 1][k - (1 << j - 1)][1]);
        }
        rep(j, 1, q) if(L[j] < R[j] && (L[j] != 1 || R[j] != n)) {
            int z = __builtin_clz(R[j] - L[j]) ^ 31;
            int l = min(g[z][R[j]][0], g[z][L[j] + (1 << z)][0]);
            int r = max(g[z][R[j]][1], g[z][L[j] + (1 << z)][1]);
            if(l != 1 || r != n) L[j] = l, R[j] = r, ans[j] += 1 << i;
            if(l >= r) ans[j] = (1 << 18) - 1;
        }
    }
    rep(i, 1, q) if(L[i] == 1 && R[i] == n) memcpy(IO.out, "0\n", 2), IO.out += 2;
    else if(ans[i] == (1 << 18) - 1 || L[i] == R[i]) memcpy(IO.out, "-1\n", 3), IO.out += 3;
    else IO.write(ans[i] + 1);
}