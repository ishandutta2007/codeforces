#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 72, M = 1e6, mod = 998244353;
int qpow(int x, int y = mod - 2) {
    int res = 1;
    for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
    return res;
}
int fac[N], ifac[N], inv[N];
void init(int x) {
    fac[0] = ifac[0] = inv[1] = 1;
    L(i, 2, x) inv[i] = (ll) (mod - mod / i) * inv[mod % i] % mod;
    L(i, 1, x) fac[i] = (ll) fac[i - 1] * i % mod, ifac[i] = (ll) ifac[i - 1] * inv[i] % mod;
}
int C(int x, int y) {
    return x < y || y < 0 ? 0 : (ll) fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
int n, o, p, ca[N], up[N], ns, iv = qpow (M);
double a[N];
int DP[2][N][N][N][N]; // Pos; using 1; min; mindec; poly
inline void Add (int b, int c, int d, int e, int w) {
    if(ca[p] - M * b <= ca[c] - M * d)
        c = p, d = b;
    if (b < 0) return ;
    if (ca[p] - M * b < 0) return ;
    (DP[o][b][c][d][e] += w) %= mod;
}
int pw[N][N][N];
int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    init (n + 1);
    L(i, 1, n) cin >> a[i], ca[i] = (int) (a[i] * M + 0.5);
    L(i, 1, n) ca[i] = min(ca[i], i * M);
    o = 0;
    L(i, 0, n) DP[o][i][n][i][0] = (i & 1) ? mod - 1 : 1;
    L(i, 1, n) {
        L(j, 0, n) {
            int U = (ll) (ca[i] - M * j) * qpow (M) % mod;
            pw[i][j][0] = 1;
            L(k, 1, n) pw[i][j][k] = (ll) pw[i][j][k - 1] * U % mod;
        }
    }
    R(i, n, 1) {
        o ^= 1, p = i - 1;
        L(j, 0, ca[i] / M) L(k, i, n) L(u, j, n) L(r, 0, n - i) if(DP[o ^ 1][j][k][u][r]) {
            DP[o ^ 1][j][k][u][r] = (ll) DP[o ^ 1][j][k][u][r] * inv[r + 1] % mod;
            int Z = mod - DP[o ^ 1][j][k][u][r];
            Add (j, k, u, r + 1, Z);
            Add (j - 1, k, u, r + 1, Z);
            Z = (ll) DP[o ^ 1][j][k][u][r] * pw[k][u][r + 1] % mod;
            Add (j, k, u, 0, Z);
            Add (j - 1, k, u, 0, Z);
            DP[o ^ 1][j][k][u][r] = 0;
        }
    }
    cout << DP[o][0][0][0][0] << '\n';
    return 0;
}