#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = long long;

const int N = 1e5 + 5;

int n, m, d[N][2];
struct mat {
    ll a[2][2];
    mat operator*(const mat& b) {
        mat c;
        rep(i, 0, 1) rep(j, 0, 1)
            c.a[i][j] = min(a[i][0] + b.a[0][j], a[i][1] + b.a[1][j]);
        return c;
    }
} f[17][N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    int x, y;
    For(i, 1, n) {
        cin >> x >> y, d[i][0] = y;
        cin >> x >> y, d[i][1] = i * 2 - x;
    }
    rep(i, 1, n) rep(a, 0, 1) rep(b, 0, 1)
        f[0][i].a[a][b] = abs(d[i - 1][a] + a * 2 - d[i][b]) + 1;
    rep(i, 1, 16) rep(j, 1 << i, n)
        f[i][j] = f[i - 1][j - (1 << i - 1)] * f[i - 1][j];
    cin >> m;
    int x1, y1, x2, y2;
    while(m--) {
        cin >> x >> y;
        if(x > y) x1 = x, y1 = y;
        else x1 = y, y1 = y * 2 - x;
        cin >> x >> y;
        if(x > y) x2 = x, y2 = y;
        else x2 = y, y2 = y * 2 - x;
        if(x1 == x2) { cout << abs(y1 - y2) << '\n'; continue; }
        if(x1 > x2) swap(x1, x2), swap(y1, y2);
        x2--;
        mat res;
        res.a[0][0] = res.a[0][1] = abs(d[x2][0] - y2) + 1;
        res.a[1][0] = res.a[1][1] = abs(d[x2][1] + 2 - y2) + 1;
        rep(i, 0, 16) if(x2 - x1 >> i & 1) res = f[i][x2] * res, x2 -= 1 << i;
        cout << min(abs(d[x1][0] - y1) + res.a[0][0], abs(d[x1][1] - y1) + res.a[1][0]) << '\n';
    }
}