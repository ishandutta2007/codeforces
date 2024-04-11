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
    static const int bufSize = 1 << 17;
    char inBuf[bufSize], *in1, *in2;
    inline __attribute((always_inline))
    ll read() {
        if(in1 > inBuf + bufSize - 32) [[unlikely]] {
            auto len = in2 - in1;
            memcpy(inBuf, in1, len);
            in1 = inBuf, in2 = inBuf + len;
            in2 += fread(in2, 1, bufSize - len, stdin);
            if(in2 != inBuf + bufSize) *in2 = 0;
        }
        ll res = 0;
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

const int N = 5e4 + 5, P = 1e9 + 7;

int n, a[N], b[N], mid[N][2], cnt[N][30];
ll m;

struct S {
    int l, r;
    int find(int k) {
        int L = l, R = r;
        while(L != R) {
            int m = L + R >> 1;
            a[m] & k ? R = m : L = m + 1;
        }
        return L;
    }
} A[N][2], B[N][2];

inline void ins(int l1, int r1, int l2, int r2, int& idx) {
    if(l1 != r1 && l2 != r2) B[++idx][0] = {l1, r1}, B[idx][1] = {l2, r2};
}
inline ll calc(int l1, int k1, int r1, int l2, int k2, int r2) {
    ll res = 0;
    #pragma GCC unroll 30
    per(i, 29, 0) {
        ll c1L = cnt[l1][i] - cnt[k1][i], c1R = cnt[k1][i] - cnt[r1][i];
        ll c2L = cnt[l2][i] - cnt[k2][i], c2R = cnt[k2][i] - cnt[r2][i];
        res = res * 2 + c1L * (r2 - k2 - c2R) + (k1 - l1 - c1L) * c2R + c1R * (k2 - l2 - c2L) + (r1 - k1 - c1R) * c2L;
    }
    return res;
}
int main() {
    n = IO.read(), m = IO.read() << 1;
    int buc[4][256] = {};
    rep(i, 1, n) {
        a[i] = IO.read();
        buc[0][a[i] & 255]++;
        buc[1][a[i] >> 8 & 255]++;
        buc[2][a[i] >> 16 & 255]++;
        buc[3][a[i] >> 24]++;
    }
    rep(i, 1, 255)
    #pragma GCC unroll 4
    rep(j, 0, 3) buc[j][i] += buc[j][i - 1];
    per(i, n, 1) b[buc[0][a[i] & 255]--] = a[i];
    per(i, n, 1) a[buc[1][b[i] >> 8 & 255]--] = b[i];
    per(i, n, 1) b[buc[2][a[i] >> 16 & 255]--] = a[i];
    per(i, n, 1) a[buc[3][b[i] >> 24]--] = b[i];
    per(i, n, 1) {
        memcpy(cnt[i], cnt[i + 1], sizeof cnt[i]);
        #pragma GCC unroll 30
        rep(j, 0, 29) cnt[i][j] += a[i] >> j & 1;
    }
    int idx = 1, val = 0;
    ll ans = 0;
    A[1][0] = A[1][1] = {1, n + 1};
    for(int k = 1 << 29; k; k >>= 1) {
        ll cnt = 0;
        rep(i, 1, idx) {
            mid[i][0] = A[i][0].find(k);
            mid[i][1] = A[i][1].find(k);
            cnt += ll(mid[i][0] - A[i][0].l) * (A[i][1].r - mid[i][1]) + ll(A[i][0].r - mid[i][0]) * (mid[i][1] - A[i][1].l);
        }
        int idx2 = 0;
        if(m > cnt) {
            m -= cnt;
            rep(i, 1, idx) {
                ans += calc(A[i][0].l, mid[i][0], A[i][0].r, A[i][1].l, mid[i][1], A[i][1].r);
                ins(A[i][0].l, mid[i][0], A[i][1].l, mid[i][1], idx2);
                ins(mid[i][0], A[i][0].r, mid[i][1], A[i][1].r, idx2);
            }
        } else {
            val += k;
            rep(i, 1, idx) {
                ins(A[i][0].l, mid[i][0], mid[i][1], A[i][1].r, idx2);
                ins(mid[i][0], A[i][0].r, A[i][1].l, mid[i][1], idx2);
            }
        }
        idx = idx2, memcpy(A + 1, B + 1, idx * sizeof A[0]);
    }
    cout << (ans + m * val) / 2 % P;
}