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
    static const int inSZ = 1 << 17;
    char inBuf[inSZ], *in1, *in2;
    inline __attribute((always_inline))
    int read() {
        if(__builtin_expect(in1 > inBuf + inSZ - 32, 0)) {
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
    void write(long double x0) {
        if(__builtin_expect(out > outBuf + outSZ - 32, 0))
            fwrite(outBuf, 1, out - outBuf, stdout), out = outBuf;
        ll x = x0, y = (x0 - x) * 1e6;
        alignas(2) const char* digits =
        "0001020304050607080910111213141516171819"
        "2021222324252627282930313233343536373839"
        "4041424344454647484950515253545556575859"
        "6061626364656667686970717273747576777879"
        "8081828384858687888990919293949596979899";
        alignas(2) static char buf[30];
        char* p = buf + 30;
        *--p = '\n';
        for(int i = 3; i; i--) memcpy(p -= 2, digits + y % 100 * 2, 2), y /= 100;
        *--p = '.';
        if(x) {
            while(x >= 10) memcpy(p -= 2, digits + x % 100 * 2, 2), x /= 100;
            if(x) *--p = 48 + x;
        } else *--p = '0';
        auto len = buf + 30 - p;
        memcpy(out, p, len), out += len;
    }
    inline __attribute((always_inline))
    void writeZ() {
        if(__builtin_expect(out > outBuf + outSZ - 32, 0))
            fwrite(outBuf, 1, out - outBuf, stdout), out = outBuf;
        memcpy(out, "0\n", 2), out += 2;
    }
    IO() {
        in1 = inBuf;
        in2 = in1 + fread(in1, 1, inSZ, stdin);
        out = outBuf;
    }
    ~IO() { fwrite(outBuf, 1, out - outBuf, stdout); }
} IO;

const int N = 3e5 + 8;

int n, rk[N];
long double p[N], q[N], sl[N], isl[N];
struct L {
    uint32_t p, q;
    int i;
    bool operator <(const L& b)const {
        return (uint64_t)q * b.p < (uint64_t)b.q * p;
    }
} a[N];

void solve() {
    n = IO.read();
    long double x1 = IO.read(), x2 = x1, y1 = IO.read(), y2 = y1;
    rep(i, 1, n) a[i].p = IO.read(), a[i].i = i;
    rep(i, 1, n) a[i].q = IO.read();
    if(x1 == 0 && y1 == 0) {
        rep(i, 1, n) IO.writeZ();
        return;
    }
    sort(a + 1, a + n + 1);
    rep(i, 1, n) {
        rk[a[i].i] = i, p[i] = a[i].p, q[i] = a[i].q;
        sl[i] = p[i] / q[i], isl[i] = q[i] / p[i];
    }
    set<int> s;
    rep(k, 1, n) {
        int i = rk[k];
        x1 += p[i], y1 -= q[i], x2 -= p[i], y2 += q[i];
        p[i] *= 2, q[i] *= 2, s.insert(i);
        while(s.size()) {
            int j = *prev(s.end());
            if(y1 + q[j] < 0) y1 += q[j], x1 -= p[j], s.erase(prev(s.end()));
            else {
                if(y1 < 0) {
                    auto z = y1 * sl[j];
                    x1 += z, p[j] += z, q[j] += y1, y1 = 0;
                }
                break;
            }
        }
        while(s.size()) {
            int j = *s.begin();
            if(x2 + p[j] < 0) x2 += p[j], y2 -= q[j], s.erase(s.begin());
            else {
                if(x2 < 0) {
                    auto z = x2 * isl[j];
                    y2 += z, q[j] += z, p[j] += x2, x2 = 0;
                }
                break;
            }
        }
        IO.write(x1);
    }
}
int main() {
    int T = IO.read();
    while(T--) solve();
}