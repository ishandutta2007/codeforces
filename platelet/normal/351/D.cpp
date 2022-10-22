#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;

const int N = 1e5 + 5, M = 1 << 17;

int n, q, a[N], ans[N], c[N], m[M * 2 + 5];
int lst[N], pre[N], dis[N], s[N];
vector<pair<int, int>> b[N];

void add(int i, int v) {
    for(; i <= n; i += i & -i) c[i] += v;
}
int qry(int i, int r = 0) {
    for(; i; i &= i - 1) r += c[i];
    return r;
}
void upd(int i, int v) {
    for(m[i |= M] = v, i >>= 1; i; i >>= 1)
        m[i] = min(m[i << 1], m[i << 1 | 1]);
}
int Qry(int i, int r = m[0]) {
    for(i |= M; i; i >>= 1)
        if(~i & 1) r = min(r, m[i ^ 1]);
    return r;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    mem(m, 63);
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    cin >> q;
    int l, r;
    rep(i, 1, q) cin >> l >> r, b[r].emplace_back(--l, i);
    rep(i, 1, n) {
        int& l = lst[a[i]];
        if(l) {
            add(l, -1), upd(l, m[0]);
            pre[i] = l, dis[i] = i - l;
            s[i] = dis[i] == dis[l] ? s[l] : pre[l];
        }
        add(i, 1), upd(i, s[i]), l = i;
        for(auto [l, id] : b[i]) ans[id] = qry(i) - qry(l) + (Qry(l) > l);
    }
    rep(i, 1, q) cout << ans[i] << '\n';
}