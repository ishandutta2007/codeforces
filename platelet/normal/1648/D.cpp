#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); i++)
#define per(i, r, l) for (int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for (int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = long long;

const int N = 5e5 + 5, inf = 0x3f3f3f3f;

int n, q, p[N][2], w[N];
int s[20][N];
ll a[3][N], f[N], ans = -1e18;

int read() {
    const int M = 1e6;
    static streambuf* in = cin.rdbuf();
    #define gc (p1 == p2 && (p2 = (p1 = buf) + in -> sgetn(buf, M), p1 == p2) ? -1 : *p1++)
    static char buf[M], *p1, *p2;
    int c = gc, r = 0, f = 1;
    for(; c < 48; c = gc) if(c == 45) f = -1;
    while(c > 47) r = r * 10 + (c & 15), c = gc;
    return r * f;
}
void cmax(ll& a, ll b) { if(a < b) a = b; }
void solve(int l, int r, int d, int n, int mn) {
    if(l == r) {
        if(l) cmax(ans, f[l] + a[2][::n] - a[2][l - 1] + a[1][l]);
        cmax(f[l], a[0][l + 1] - a[1][l]);
        return;
    }
    int m = 0;
    rep(i, 1, n) {
        int x = s[d - 1][i], L = p[x][0], R = p[x][1];
        if(L <= l && r <= R) mn = min(mn, w[x]);
        else if(L <= r && l <= R) s[d][++m] = x;
    }
    int mid = l + r >> 1;
    solve(l, mid, d + 1, m, mn);
    per(i, mid - 1, l) cmax(f[i], f[i + 1]);
    if(mn < inf) cmax(f[r], f[l] - mn);
    rep(i, 1, m) {
        int x = s[d][i];
        cmax(f[min(p[x][1], r)], f[max(p[x][0], l)] - w[x]);
    }
    per(i, r - 1, mid + 1) cmax(f[i], f[i + 1]);
    solve(mid + 1, r, d + 1, m, mn);
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    rep(i, 0, 2) rep(j, 1, n) a[i][j] = read() + a[i][j - 1];
    rep(i, 1, q) p[i][0] = read() - 1, p[i][1] = read(), w[i] = read(), s[0][i] = i;
    mem(f, 192), solve(0, n, 1, q, inf);
    cout << ans;
}