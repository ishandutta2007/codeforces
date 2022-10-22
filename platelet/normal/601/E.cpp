#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define lc (o << 1)
#define rc (o << 1 | 1)
#define mid (l + r >> 1)
#define lch l, mid, lc
#define rch mid + 1, r, rc

using namespace std;
using ll = long long;

const int N = 30000 + 5, P = 1e7 + 19, Q = 1e9 + 7;

int n, k, q, idx, s[N], A[N], B[N];
bool isq[N];
vector<pair<int, int>> c[N * 4];
ll f[18][1005];

void push(int a, int b, int L, int R, int l, int r, int o) {
    if(L <= l && r <= R) return void(c[o].emplace_back(a, b));
    if(L <= mid) push(a, b, L, R, lch);
    if(R > mid) push(a, b, L, R, rch);
}
void solve(int d, int l, int r, int o) {
    memcpy(f[d], f[d - 1], sizeof f[d]);
    for(auto [a, b] : c[o]) per(i, k, b) f[d][i] = max(f[d][i], f[d][i - b] + a);
    if(l < r) solve(d + 1, lch), solve(d + 1, rch);
    else if(isq[l]) {
        ll ans = 0, p = 1;
        rep(i, 1, k) (ans += f[d][i] * p) %= Q, p = p * P % Q;
        cout << ans << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    rep(i, 1, n) s[++idx] = 1, cin >> A[i] >> B[i];
    cin >> q;
    rep(i, 1, q) {
        int t; cin >> t;
        if(t == 1) s[++idx] = i, cin >> A[idx] >> B[idx];
        if(t == 3) isq[i] = 1;
        if(t == 2) cin >> t, push(A[t], B[t], s[t], i, 1, q, 1), s[t] = 0;
    }
    rep(i, 1, idx) if(s[i]) push(A[i], B[i], s[i], q, 1, q, 1); 
    solve(1, 1, q, 1);
}