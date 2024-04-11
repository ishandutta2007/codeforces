#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = long long;

const int N = 200 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;

int n, m, K;
ll a[N], b[N], c[N], sa[N], sb[N], f[N][N][2], g[N][N][2];

void cmin(ll &a, ll b) { if(b < a) a = b; }
int main() {
    cin >> n >> m >> K;
    rep(i, 1, n) scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
    a[n + 1] = inf >> 1, b[n + 1] = inf >> 9, c[n + 1] = inf;
    rep(i, 1, n + 1) sa[i] = sa[i - 1] + a[i], sb[i] = sb[i - 1] + b[i];
    mem(f, 63), mem(g, 63), mem(f[0], 0), mem(g[0], 0);
    rep(i, 1, n + 1) rep(j, 0, m) rep(k, 0, 1) {
        if(f[i - 1][j][k] < inf && k * a[i] + j * b[i] <= c[i]) {
            f[i][j][k] = f[i - 1][j][k];
            ll t = (k * sa[i - 1] + j * sb[i - 1] + K - 1) / K;
            if(t * K <= k * sa[i] + j * sb[i]) g[i][j][k] = t;
        }
        For(r, 0, j) if(g[i][r][k] < inf) {
            ll m = k * sa[i] + r * sb[i] - g[i][r][k] * K;
            ll x = max(m - c[i] + (j - r) * b[i] + K - 1, 0LL) / K;
            if(m < x * K || f[i - 1][j - r][0] == inf) continue;
            cmin(f[i][j][k], g[i][r][k] + x + f[i - 1][j - r][0]);
            ll t = ((j - r) * sb[i - 1] + K - 1) / K;
            if(t * K <= (j - r) * sb[i] + m) cmin(g[i][j][k], g[i][r][k] + x + t);
        }
    }
    cout << f[n + 1][m][1];
}