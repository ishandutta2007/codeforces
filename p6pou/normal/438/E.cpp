#include <bits/stdc++.h>

using namespace std;

const int BUFFER_SIZE = 1 << 20;
char rb[BUFFER_SIZE], *rp = rb, *rt = rb;
inline char read_char() {
    return rp == rt ? (rt = rb + fread(rb, 1, BUFFER_SIZE, stdin), rp = rb, *rp ++) : *rp ++;
}
inline int read_int() {
    int x = 0;
    char ch = read_char(), flag = 0;
    while (ch != '-' && (ch < '0' || ch > '9')) {
        ch = read_char();
    }
    if (ch == '-') {
        flag = 1;
        ch = read_char();
    }
    for (x = 0; ch >= '0' && ch <= '9'; ch = read_char()) {
        x = x * 10 + (ch - '0');
    }
    return flag ? -x : x;
}

const int MAX_NTT = 1 << 18 | 5;
const int P = 998244353, g = 3;

int power_mod(int a, int b) {
    int c = 1;
    for (; b; a = 1ll * a * a % P, b >>= 1) {
        c = b & 1 ? 1ll * c * a % P : c;
    }
    return c;
}
int sqrt_mod(int a0) {
    if (a0 == 0 || a0 == 1) return a0;
    if (power_mod(a0, P - 1 >> 1) == P - 1) return -1;
    int w, a, b = 1, c = 1, d = 0, x, y;
    do {
        a = (rand() << 15 | rand()) % P; 
        w = (1ll * a * a - a0 + P) % P;
    } while (power_mod(w, P - 1 >> 1) != P - 1);
    for (int m = P + 1 >> 1; m; m >>= 1) {
        if (m & 1) {
            x = (1ll * c * a + 1ll * d * b % P * w) % P;
            y = (1ll * c * b + 1ll * a * d) % P;
            c = x, d = y;
        }
        x = (1ll * a * a + 1ll * b * b % P * w) % P;
        y = (1ll * a * b + 1ll * b * a) % P;
        a = x, b = y;
    }
    return min(c, P - c);
}
namespace Poly {
    const int* ntt_get_rev(int n) {
        static int* rev[MAX_NTT];
        if (!rev[n]) {
            register int* rn = new int [n];
            rn[0] = 0;
            for (register int i = 0, j = 0; i < n; i ++) {
                rn[i] = i < j ? j : i;
                for (register int k = n >> 1; (j ^= k) < k; k >>= 1);
            }
            rev[n] = rn;
        }
        return rev[n];
    }
    const int* ntt_get_omega(int m) {
        static int *w[MAX_NTT];
        if (!w[m]) {
            register int* wm = new int[m];
            register int w0 = power_mod(g, (P - 1 >> 1) / m);
            wm[0] = 1;
            if (m > 1) {
                register const int* wk = ntt_get_omega(m >> 1);
                for (register int i = 0; i < m; i += 2) wm[i + 1] = 1ll * (wm[i] = wk[i >> 1]) * w0 % P;
            }
            w[m] = wm;
        }
        return w[m];
    }
    void ntt(int a[], int n, int ty) {
        const int* rev = ntt_get_rev(n);
        register int t0, t1;
        for (int i = 0; i < n; i ++) t0 = a[i], a[i] = a[rev[i]], a[rev[i]] = t0;
        for (int m = 1; m < n; m <<= 1) {
            const int *w = ntt_get_omega(m);
            for (register int k = 0; k < n; k += m << 1) {
                for (register int i = k; i < k + m; i ++) {
                    t0 = a[i];
                    t1 = 1ll * a[i + m] * w[i - k] % P;
                    a[i] = t0 + t1 - (t0 + t1 >= P ? P : 0);
                    a[i + m] = t0 - t1 + (t0 - t1 < 0 ? P : 0);
                }
            }
        }
        if (ty == 1) return;
        for (register int i = 1; i < n - i; i ++) t0 = a[i], a[i] = a[n - i], a[n - i] = t0;
        t0 = power_mod(n, P - 2);
        for (register int i = 0; i < n; i ++) a[i] = 1ll * a[i] * t0 % P;
    }
    void inv(int a[], int na, int b[], int nb) {
        static int c[MAX_NTT];
        for (int i = 0; i < nb; i ++) b[i] = 0;
        b[0] = power_mod(a[0], P - 2);
        for (int m = 1; m < nb; m <<= 1) {
            for (register int i = 0; i < m << 1; i ++) c[i] = a[i];
            ntt(c, m << 2, 1);
            ntt(b, m << 2, 1);
            for (register int i = 0; i < m << 2; i ++) b[i] = (2 + P - 1ll * b[i] * c[i] % P) * b[i] % P;
            ntt(b, m << 2, -1);
            for (register int i = m << 1; i < m << 2; i ++) b[i] = 0;
        }
        for (int i = 0; i < nb << 1; i ++) c[i] = 0;
    }
    void sqrt(int a[], int na, int b[], int nb) {
        static int c[MAX_NTT], d[MAX_NTT];
        for (int i = 0; i < nb; i ++) b[i] = 0;
        b[0] = sqrt_mod(a[0]);
        for (int m = 1; m < nb; m <<= 1) {
            for (register int i = 0; i < m << 1; i ++) c[i] = a[i];
            ntt(c, m << 2, 1);
            inv(b, m, d, m << 1);
            ntt(d, m << 2, 1);
            ntt(b, m << 2, 1);
            for (register int i = 0, t = P + 1 >> 1; i < m << 2; i ++) b[i] = (b[i] + 1ll * c[i] * d[i] % P) * t % P;
            ntt(b, m << 2, -1);
            for (register int i = m << 1; i < m << 2; i ++) b[i] = 0;
        }
        for (register int i = 0; i < nb << 1; i ++) c[i] = 0;
        for (register int i = 0; i < nb << 1; i ++) d[i] = 0;
    }
}

int main() {
    srand(12345);
    static int N, M, n;
    static int b[MAX_NTT], c[MAX_NTT];
    N = read_int();
    M = read_int();
    for (int i = c[0] = 1; i <= N; i ++) c[read_int()] = P - 4;
    for (n = 1; n <= M; n <<= 1);
    Poly::sqrt(c, n, b, n);
    for (int i = 0, t = P + 1 >> 1; i < n; i ++) b[i] = 1ll * (b[i] + !i) * t % P;
    Poly::inv(b, n, c, n);
    for (int i = 1; i <= M; i ++) printf("%d\n", c[i]);
    return 0;
}