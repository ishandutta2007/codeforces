#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = long long;

const int N = 2000 + 5, P = 998244353;

int n, K, b[N], f[N][N], g[N][N], A[N][N];

inline void inc(int& a, int b) { if((a += b) >= P) a -= P; }
inline void fma(int& a, int b, int c) { a = (a + (ll)b * c) % P; }
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> K;
    b[0] = -K;
    rep(i, 1, n) cin >> b[i];
    f[0][0] = 1;
    rep(i, 0, n) rep(j, 0, i) A[i][j] = j ? (A[i - 1][j - 1] * (ll)j + (ll)A[i - 1][j]) % P : 1;
    int ans = 0, L = 0, R = 0;
    rep(i, 1, n) {
        int l = max(0, b[i - 1] - K), r = min(b[i] + K, i);
        if(l > r) cout << 0, exit(0);
        rep(j, l, r - 1) rep(k, 0, i - j) {
            if(k) fma(g[j + 1][k - 1], g[j][k], k);
            inc(g[j + 1][k], f[j][k]);
        }
        rep(j, l, r) rep(k, 0, i - j) {
            fma(g[j][k], f[j][k], j + k);
            inc(g[j][k + 1], f[j][k]);
        }
        if(i < n) {
            rep(j, L, R) mem(f[j], 0);
            rep(j, l, r) memcpy(f[j], g[j], sizeof g[0]), mem(g[j], 0);
            L = l, R = r;
        } else rep(j, max(0, b[i] - K), r) rep(k, 0, i - j) fma(ans, g[j][k], A[n - j][k]);
    }
    cout << ans;
}