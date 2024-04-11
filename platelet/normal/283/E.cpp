#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define eb emplace_back
#define lc (o << 1)
#define rc (o << 1 | 1)
#define mid (l + r >> 1)
#define lch l, mid, lc
#define rch mid + 1, r, rc

using namespace std;
using ll = long long;

const int N = 1e5 + 5;

int n, K, a[N], c[N << 2];
bool t[N << 2];
vector<pair<int, int>> v[N];

void flip(int L, int R, int l, int r, int o) {
    if(L <= l && r <= R) return t[o] ^= 1, c[o] = r - l + 1 - c[o], void();
    if(L <= mid) flip(L, R, lch);
    if(R > mid) flip(L, R, rch);
    c[o] = c[lc] + c[rc];
    if(t[o]) c[o] = r - l + 1 - c[o];
}
bool qry(int i, int l, int r, int o) {
    return t[o] ^ (l < r ? i <= mid ? qry(i, lch) : qry(i, rch) : 0);
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> K;
    rep(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    int l, r;
    rep(i, 1, K) {
        cin >> l >> r;
        l = lower_bound(a + 1, a + n + 1, l) - a;
        r = upper_bound(a + 1, a + n + 1, r) - a;
        if(l < r) v[l].eb(l, r - 1), v[r].eb(l, r - 1);
    }
    ll ans = n * (n - 1LL) * (n - 2LL) / 6;
    rep(i, 1, n) {
        for(auto [l, r] : v[i]) flip(l, r, 1, n, 1);
        int d = c[1] - qry(i, 1, n, 1);
        ans -= d * (d - 1LL) / 2, flip(i, i, 1, n, 1);
    }
    cout << ans;
}