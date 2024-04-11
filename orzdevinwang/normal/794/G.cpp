#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e6 + 7;
const int mod = 1e9 + 7;
int qpow(int x, int y) {
    int res = 1;
    for(; y; x = 1ll * x * x % mod, y >>= 1) if(y & 1) res = 1ll * res * x % mod;
    return res;
}
int ny(int x) { return qpow(x, mod - 2); }
int get(int x) { return (qpow(2, x + 1) + mod - 2) % mod; }
bool Prime[N];
int mu[N], p[N], tot, d[N];
int jc[N], njc[N];
void xxs(int x) {
    mu[1] = 1;
    L(i, 2, x) {
        if(!Prime[i]) p[++tot] = i, mu[i] = -1;
        for(int j = 1; p[j] * i <= x && j <= tot; j ++) {
            Prime[p[j] * i] = 1;
            if(i % p[j] == 0) {
                mu[p[j] * i] = 0;
                break;
            }
            mu[p[j] * i] = -mu[i];
        }
    }
    L(i, 1, x) L(j, 1, x / i) (d[i * j] += 1ll * qpow(2, i) * (mu[j] + mod) % mod) %= mod;
    L(i, 1, x) (d[i] += d[i - 1]) %= mod;
    jc[0] = 1;
    L(i, 1, x) jc[i] = 1ll * jc[i - 1] * i % mod;
    njc[x] = ny(jc[x]);
    R(i, x, 1) njc[i - 1] = 1ll * njc[i] * i % mod;
}
int C(int x, int y) {
    return 1ll * jc[x] * njc[y] % mod * njc[x - y] % mod;
}
int n, lena, lenb, ans, f[N], cnt, ga, gb, pa, pb, aska, askb;
char A[N], B[N];
int work(int x) {
    int res = 0;
    for(int l = 1, r; l <= x; l = r + 1) {
        r = x / (x / l);
        (res += 1ll * (x / l) * (x / l) % mod * (d[r] - d[l - 1] + mod) % mod) %= mod;
    }
    return res;
}
void equ() {
    int res = 1;
    L(i, 1, lena) if(A[i] != '?' && B[i] != '?' && A[i] != B[i]) return;
    L(i, 1, lena) if(A[i] == '?' && B[i] == '?') res = 1ll * res * 2 % mod;
    (ans += 1ll * res * (1ll * get(n) * get(n) % mod - work(n) + mod) % mod) %= mod;
}
int js(int ts) {
    int a = ga + ts, b = gb - ts;
    if(a == 0 && b == 0) return work(n);
    if(a <= 0 && b <= 0) return 0;
    if(a >= 0 && b >= 0) return 0;
    if(b < 0) b = -b;
    else a = -a;
    int tmp = __gcd(a, b); a /= tmp, b /= tmp;
    return get(n / max(a, b));
}
int main() {
    scanf("%s%s%d", A + 1, B + 1, &n), lena = strlen(A + 1), lenb = strlen(B + 1);
    xxs(max(lena + lenb, n));
    if(lena == lenb) equ();
    L(i, 1, lena) {
        if(A[i] == 'A') ga ++;
        if(A[i] == 'B') gb ++;
        if(A[i] == '?') pa ++;
    }
    L(i, 1, lenb) {
        if(B[i] == 'A') ga --;
        if(B[i] == 'B') gb --;
        if(B[i] == '?') pb ++;
    }
    ga -= pb, gb += pa;
    L(i, 0, pa + pb) (ans += 1ll * C(pa + pb, i) % mod * js(i) % mod) %= mod;
    printf("%d\n", ans);
    return 0;
}