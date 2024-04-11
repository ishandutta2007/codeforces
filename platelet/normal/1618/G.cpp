#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define fi first
#define se second

using namespace std;
using ll = long long;

const int N = 2e5 + 5;

int n, m, q, fa[N * 2];
ll ans[N];
pair<int, int> Q[N], a[N * 2];

int find(int x) { return fa[x] <= 0 ? x : fa[x] = find(fa[x]); }

int main() {
    cin >> n >> m >> q;
    ll sum = 0;
    rep(i, 1, n) {
        scanf("%d", &a[i].fi);
        sum += a[i].fi, a[i].se = 1;
    }
    rep(i, n + 1, n + m) scanf("%d", &a[i].fi);
    rep(i, 1, q) scanf("%d", &Q[i].fi), Q[i].se = i;
    sort(a + 1, a + n + m + 1), sort(Q + 1, Q + q + 1);
    vector<pair<int, int>> ord;
    rep(i, 1, n + m) {
        fa[i] = a[i].se - i;
        if(i > 1) ord.emplace_back(a[i].fi - a[i - 1].fi, i);
    }
    sort(ord.begin(), ord.end());
    int j = 1;
    for(auto [d, i] : ord) {
        while(j <= q && Q[j].fi < d) ans[Q[j++].se] = sum;
        int x = find(i--);
        while(-fa[i] < i && -fa[x] > i) sum += a[-fa[x]++].fi - a[- --fa[i]].fi;
        if(-fa[i] < i) fa[x] = fa[i];
        fa[i] = x;
    }
    while(j <= q) ans[Q[j++].se] = sum;
    rep(i, 1, q) printf("%lld\n", ans[i]);   
}