#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define cmin(a, b) (a = min(a, b))

using namespace std;
using lf = double;
using cmp = complex<lf>;
using node = pair<double, int>;

const int N = 32768;
const lf PI = acos(-1);

int n, m, t, x, rev[N], dis0[N];
vector<tuple<int, int, array<lf, N>, array<lf, N>>> G[55];
double dis[55][N];
cmp w[N], a[N], b[N];

void FFT(cmp a[], int lim, int t) {
    if(t) reverse(a + 1, a + lim);
    For(i, 0, lim) if(i < rev[i]) swap(a[i], a[rev[i]]);
    for(int i = 1; i < lim; i <<= 1)
    for(int j = 0; j < lim; j += i << 1) For(k, j, j + i) {
        cmp &x = a[k], y = a[k + i] * w[lim / i * (k - j)];
        a[k + i] = x - y, x += y;
    }
    lf inv = 1. / lim;
    if(t) For(i, 0, lim) a[i] *= inv;
}
void solve(int l, int lim) {
    if(lim == 1) {
        rep(u, 1, n) for(auto&& [v, w, p, dp] : G[u]) cmin(dis[v][l], dp[l] + w);
        return;
    }
    solve(l, lim >> 1);
    For(i, 1, lim) rev[i] = rev[i >> 1] >> 1 | (i & 1 ? lim >> 1 : 0);
    For(i, 0, lim) w[i] = cmp(cos(PI / lim * i), sin(PI / lim * i));
    rep(u, 1, n) for(auto&& [v, w, p, dp] : G[u]) {
        fill(a, a + lim, 0);
        For(i, 0, lim >> 1) a[i] = dis[u][l + i];
        For(i, 0, lim) b[i] = p[i];
        FFT(a, lim, 0), FFT(b, lim, 0);
        For(i, 0, lim) a[i] *= b[i];
        FFT(a, lim, 1);
        For(i, lim >> 1, lim) dp[l + i] += real(a[i]);
        // For(i, lim >> 1, lim) For(j, 0, lim >> 1) dp[l + i] += dis[u][l + j] * p[i - j];
    }
    solve(l + lim / 2, lim >> 1);
}
int main() {
#ifdef local
    freopen("in", "r", stdin);
#endif
    cin >> n >> m >> t >> x;
    int u, v, w, tmp;
    array<lf, N> p, emp;
    while(m--) {
        scanf("%d%d%d", &u, &v, &w);
        rep(i, 1, t) scanf("%d", &tmp), p[i] = tmp * 1e-5;
        G[v].emplace_back(u, w, p, emp);
    }
    For(i, 1, n) rep(j, 0, t + 1) j ? dis[i][j] = 1e18 : dis0[i] = 1e9;
    priority_queue<node, vector<node>, greater<node>> q;
    dis0[n] = x, q.emplace(x, n);
    while(q.size()) {
        auto [d, u] = q.top(); q.pop();
        if(d > dis0[u]) continue;
        for(auto&& [v, w, p, dp] : G[u]) if(d + w < dis0[v])
            dis0[v] = d + w, q.emplace(d + w, v);
    }
    rep(u, 1, n) for(auto&& [v, w, p, dp] : G[u]) {
        lf sum = 0;
        per(i, t, 1) sum += p[i], dp[i] = dis0[u] * sum;
    }
    solve(1, 1 << 32 - __builtin_clz(t));
    printf("%.10lf", dis[1][t + 1]);
}