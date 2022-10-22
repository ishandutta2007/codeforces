#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;
using ll = long long;

const int N = 2e5 + 5;
const ll inf = 1e18;

struct IO {
    static const int bufSize = 1 << 17;
    char inBuf[bufSize], *in1, *in2;
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
    IO() {
        in1 = inBuf;
        in2 = in1 + fread(in1, 1, bufSize, stdin);
    }
} IO;

struct barrett {
    uint32_t m; uint64_t im;
    barrett(uint32_t m) :m(m), im(~0ull / m + 1) {}
    uint32_t mod(uint64_t x)const {
        return x - uint64_t((__uint128_t)x * im >> 64) * m;
    }
};

int n, t, g[N], c[N], d[N], val[N];

inline int sub(int a, int b) { return (a -= b) < 0 ? a + t : a; }

void sort() {
    static int t[N];
    int buc[4][256] = {};
    rep(i, 1, n) {
        buc[0][val[i] & 255]++;
        buc[1][val[i] >> 8 & 255]++;
        buc[2][val[i] >> 16 & 255]++;
        buc[3][val[i] >> 24]++;
    }
    rep(i, 1, 255)
    #pragma GCC unroll 4
    rep(j, 0, 3) buc[j][i] += buc[j][i - 1];
    per(i, n, 1) t[buc[0][val[i] & 255]--] = val[i];
    per(i, n, 1) val[buc[1][t[i] >> 8 & 255]--] = t[i];
    per(i, n, 1) t[buc[2][val[i] >> 16 & 255]--] = val[i];
    per(i, n, 1) val[buc[3][t[i] >> 24]--] = t[i];
}
int main() {
    n = IO.read(), t = IO.read();
    barrett bt(t);
    rep(i, 1, n) {
        g[i] = IO.read(), c[i] = IO.read();
        if(c[i]) c[i] = t - c[i];
        if((g[i] += c[i]) >= t) g[i] -= t;
    }
    d[1] = 0;
    ll sum = 0;
    rep(i, 2, n) {
        int x = IO.read();
        sum += x, d[i] = bt.mod(d[i - 1] + x);
    }
    rep(i, 1, n) val[i] = sub(g[i] - 1, d[i]);
    sort(), val[0] = -1;
    map<int, ll> p;
    rep(i, 1, n) if(val[i] != val[i - 1]) p.emplace_hint(p.end(), val[i], 0);
    rep(i, 1, n) {
        int l = sub(g[i], d[i]), r = sub(c[i], d[i]);
        ll mn = inf;
        auto it = p.lower_bound(l);
        if(r < l) {
            while(it != p.end()) mn = min(mn, it->second + r - it->first + t), it = p.erase(it);
            it = p.begin();
        }
        while(it != p.end() && it->first <= r) mn = min(mn, it->second + r - it->first), it = p.erase(it);
        if(mn != inf) p[r] = mn;
    }
    ll ans = inf;
    for(auto [a, b] : p) ans = min(ans, b);
    cout << ans + sum;
}