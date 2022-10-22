#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

const int N = 1e5 + 5;

int n, q, A[17][N][31];

struct IO {
    static const int bufSize = 1 << 17;
    char inBuf[bufSize], outBuf[bufSize], *in1, *in2, *out;
    inline __attribute((always_inline))
    int read() {
        if(in1 > inBuf + bufSize - 32) [[unlikely]] {
            auto len = in2 - in1;
            memcpy(inBuf, in1, len);
            in1 = inBuf, in2 = inBuf + len;
            in2 += fread(in2, 1, bufSize - len, stdin);
            if(in2 != inBuf + bufSize) *in2 = 0;
        }
        int res = 0;
        char c;
        while((c = *in1++) < 48);
        while(res = res * 10 + c - 48, (c = *in1++) >= 48);
        return res;
    }
    inline __attribute((always_inline))
    void write(int x) {
        if(out > outBuf + bufSize - 32) [[unlikely]]
            fwrite(outBuf, 1, out - outBuf, stdout), out = outBuf;
        const char digits[201] =
        "0010203040506070809001112131415161718191"
        "0212223242526272829203132333435363738393"
        "0414243444546474849405152535455565758595"
        "0616263646566676869607172737475767778797"
        "0818283848586878889809192939495969798999";
        static char buf[12];
        char* p = buf + 1;
        while(x >= 10) memcpy(p, digits + x % 100 * 2, 2), p += 2, x /= 100;
        if(x) *p++ = 48 + x;
        do *out++ = *--p; while(p > buf + 1);
    }
    IO() {
        in1 = out = outBuf;
        in2 = in1 + fread(in1, 1, bufSize, stdin);
    }
    ~IO() { fwrite(outBuf, 1, out - outBuf, stdout); }
} IO;

inline __attribute((always_inline))
void merge(int* dst, int* src1, int* src2) {
    rep(i, 1, 31) *dst++ = *(*src1 < *src2 ? src1++ : src2++);
}
void solve() {
    n = IO.read();
    rep(i, 1, n) {
        mem(A[0][i], 127);
        A[0][i][0] = IO.read();
    }
    rep(i, 1, 16) rep(j, 1 << i, n) merge(A[i][j], A[i - 1][j], A[i - 1][j - (1 << i - 1)]);
    q = IO.read();
    while(q--) {
        int l = IO.read() - 1, r = IO.read();
        int now[31], tmp[31];
        mem(now, 127);
        per(i, 16, 0) if(r - (1 << i) >= l)
            merge(tmp, now, A[i][r]), memcpy(now, tmp, sizeof tmp), r -= 1 << i;
        int ans = INT_MAX;
        rep(i, 0, 30) rep(j, i + 1, 30) ans = min(ans, now[i] | now[j]);
        IO.write(ans), *IO.out++ = 10;
    }
}
int main() {
    int T;
    for(T = IO.read(); T--; solve());
}