#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define fi first
#define se second
#pragma GCC target("bmi,bmi2")

using namespace std;
using ll = long long;

const int N = 1e5 + 5;
const ll inf = -0x3f3f3f3f3f3f3f3f;

int n;
ll K, a[N], c[N], mi[N];
__int128 b[N];
pair<__int128, ll> f[N], g[N], st[N][18];
vector<pair<ll, int>> seq = {{0, 0}};

struct {
    ll c[N];
    void add(int i, ll v) {
        for(; i <= n; i += i & -i) c[i] += v;
    }
    ll qry(int i, ll r = 0) {
        for(; i; i &= i - 1) r += c[i];
        return r;
    }
} A, B;


int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> K;
    vector<int> ord;
    rep(i, 1, n) {
        cin >> a[i], a[i] += a[i - 1], ord.pb(i);
        mi[i] = i > 1 ? min(mi[i - 1], a[i]) : a[i];
    }
    sort(ord.begin(), ord.end(), [](int x, int y) { return a[x] < a[y]; });
    rep(i, 1, n) if(a[i] < seq.back().fi) seq.emplace_back(a[i], i);
    seq.emplace_back(inf, n + 1);
    ll l = -5e9, r = 5e9, ans;
    while(l <= r) {
        ll mid = l + r >> 1;
        mem(A.c, 0), mem(B.c, 0), mem(f, 192);
        int j = 0;
        for(int i : ord) {
            for(int k; j < n && (k = ord[j], a[k] + mid <= a[i]); j++) A.add(k, 1), B.add(k, a[k]);
            c[i] = (a[i] >= mid) + A.qry(i - 1);
            b[i] = (a[i] - mid) * c[i] - B.qry(i - 1);
        }
        f[0] = {};
        rep(i, 1, n) {
            b[i] += b[i - 1], c[i] += c[i - 1];
            int j = lower_bound(seq.begin(), seq.end(), pair(a[i] - mid, i), greater())->se;
            if(j < i) {
                int t = __lg(i - j);
                auto [x, y] = max(st[i - 1][t], st[j + (1 << t) - 1][t]);
                f[i] = max(f[i], pair(x + b[i], y + c[i]));
            }
            if(j = min(i, j) - 1; ~j) f[i] = max(f[i], pair(g[j].fi + a[i] + b[i] - mid, g[j].se + c[i] + 1));
            g[i] = max(g[i - 1], pair(f[i].fi - b[i] - mi[i], f[i].se - c[i]));
            st[i][0] = pair(f[i].fi - b[i], f[i].se - c[i]);
            rep(j, 1, __lg(i)) st[i][j] = max(st[i][j - 1], st[i - (1 << j - 1)][j - 1]);
        }
        if(f[n].se >= K) ans = f[n].fi + K * mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans;
}