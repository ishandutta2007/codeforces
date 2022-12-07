#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 100005;
const int mod = 1000000007;

int c00, c01, c10, c11, d0, d1, len;
char a[N], b[N];
int fac[N*2+10], inv[N*2+10];

int read_bin(char *s) {
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; i++) s[i] -= '0';
    return n;
}

int power(int a, int b) {
    int r = 1;
    while (b) {
        if (b & 1) r = LL(r) * a % mod;
        a = LL(a) * a % mod;
        b >>= 1;
    }
    return r;
}

int calc(int n, int k) {
    if (n == 0) return 1;
    if (k == 0) return 0;
    int r = LL(fac[n+k-1]) * inv[k-1] % mod;
    r = LL(r) * inv[n] % mod;
    return r;
}

int solve(char *s, int sz, bool inclusive=false) {
    if (sz > len) {
        return LL(calc(c00,d0)) * calc(c11,d1) % mod;
    }
    if (sz < len) return 0;
    int dem[2][2];
    dem[0][0] = dem[0][1] = dem[1][0] = dem[1][1] = 0;
    int n0 = d0, n1 = d1, r0 = c00, r1 = c11;
    int res = 0;
    for (int i = 0; i < sz; i++) {
        if (s[i] == 1 && i > 0) {
            int m0 = n0, m1 = n1, z0 = r0, z1 = r1;
            if (s[i-1] == 1) {
                m1--;
            }
            else {
                z0--;
            }
            if (z0 >= 0 && m0 >= 0 && m1 >= 0 && z1 >= 0) {
                res += LL(calc(z0,m0)) * calc(z1,m1) % mod;
                if (res >= mod) res -= mod;
            }
        }
        if (i > 0) {
            if (s[i] == 0) {
                if (s[i-1] == 1) n1--;
                else r0--;
            }
            else {
                if (s[i-1] == 0) n0--;
                else r1--;
            }
            dem[s[i-1]][s[i]]++;
        }
    }
    if (inclusive && dem[0][0] == c00 && dem[0][1] == c01 && dem[1][0] == c10 && dem[1][1] == c11) {
        res++;
        if (res >= mod) res -= mod;
    }
    return res;
}

int main() {
    int lena = read_bin(a);
    int lenb = read_bin(b);
    scanf("%d%d%d%d", &c00, &c01, &c10, &c11);
    if (c10 < c01 || c10-c01 > 1) {
        puts("0"); return 0;
    }
    d1 = 1 + c01;
    d0 = c10;
    len = d1 + d0 + c00 + c11;
    if (len > lenb) {
        puts("0"); return 0;
    }
    int mx = len * 2 + 5;

    fac[0] = 1;
    inv[0] = 1;
    for (int i = 1; i <= mx; i++) {
        fac[i] = LL(fac[i-1]) * i % mod;
        inv[i] = power(fac[i], mod-2);
    }

    int ra = solve(a,lena);
    int rb = solve(b,lenb,true);
    rb -= ra;
    if (rb < 0) rb += mod;
    printf("%d\n", rb);
}