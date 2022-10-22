#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define lc o * 2
#define rc o * 2 + 1
#define mid ((l + r) >> 1)
#define lch l, mid, lc
#define rch mid + 1, r, rc

using namespace std;

const int N = 5e5 + 5;

int n, q, a[N], ls[N], pre[N], c[N * 4], ans[N];
vector<pair<int, int>> Q[N];
int ch(int a, int b) {
    return pre[a] < pre[b] ? a : b;
}
void upd(int i, int l, int r, int o) {
    if(l == r) c[o] = l;
    else i <= mid ? upd(i, lch) : upd(i, rch), c[o] = ch(c[lc], c[rc]);
}
int qry(int L, int R, int l, int r, int o) {
    if(L <= l && r <= R) return pre[c[o]] < L ? c[o] : 0;
    int res = 0;
    if(L <= mid) res = ch(res, qry(L, R, lch));
    if(R > mid) res = ch(res, qry(L, R, rch));
    return res;
}
int main() {
    pre[0] = 1e9;
    cin >> n;
    rep(i, 1, n) scanf("%d", &a[i]);
    cin >> q;
    int l, r;
    rep(i, 1, q) scanf("%d%d", &l, &r), Q[r].emplace_back(l, i);
    rep(i, 1, n) {
        int& x = ls[a[i]];
        if(x) pre[x] = 1e9, upd(x, 1, n, 1);
        pre[i] = x, upd(i, 1, n, 1), x = i;
        for(auto [l, id] : Q[i]) ans[id] = a[qry(l, i, 1, n, 1)];
    }
    rep(i, 1, q) printf("%d\n", ans[i]);
}