#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = long long;

const int N = 1e5 + 5;

int n, f[N];
ll a, b, c, d, g[N];
pair<ll, ll> p[N];

void add(int i, int v) {
    for(; i <= n + 1; i += i & -i) f[i] = max(f[i], v);
}
int qry(int i, int r = -0x3f3f3f3f) {
    for(; i; i &= i - 1) r = max(r, f[i]);
    return r;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> a, cin.get(), cin >> b >> c, cin.get(), cin >> d;
    int x, y;
    rep(i, 1, n) cin >> x >> y, p[i] = {c * x - d * y, a * x - b * y}, g[i] = -p[i].second;
    sort(p + 1, p + n + 1), sort(g + 1, g + n + 2);
    mem(f, 192);
    rep(i, 1, n + 1) if(!g[i]) add(i, 0);
    int ans = 0;
    rep(i, 1, n) if(p[i].first > 0) {
        y = lower_bound(g + 1, g + n + 2, -p[i].second) - g;
        add(y, x = qry(y - 1) + 1), ans = max(ans, x);
    }
    cout << ans;
}