#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define SZ(x) int((x).size())

using namespace std;

vector<pair<int, int>> a[4];

int n, m, k, ct, c0[10005], c1[80], c2[80];
int su, as = INT_MAX, K;

void ins(int x) { ct++, c0[x]++, c1[x >> 7]++, c2[x >> 7] += x; }
void upd(int k, int _K, int re = 0) {
    if(k < 0 || k > ct) return;
    rep(i, 0, 79) if(k > c1[i]) re += c2[i], k -= c1[i];
    else For(j, i << 7, i + 1 << 7) {
        int t = min(k, c0[j]);
        re += t * j, k -= t;
        if(!k) {
            if(su + re < as) as = su + re, K = _K;
            return;
        }
    }
}

int main() {
#ifdef local
    freopen("in", "r", stdin);
#endif
    int t, x, y;
    cin >> n >> m >> k;
    rep(i, 1, n) {
        scanf("%d%d%d", &t, &x, &y);
        a[x * 2 + y].emplace_back(t, i);
    }
    rep(i, 0, 3) sort(a[i].begin(), a[i].end());
    for(const auto& v : {a[1], a[2]}) {
        int i = 0;
        for(auto [x, t] : v) if(i++ <= k) su += x; else ins(x);
    }
    for(auto [x, t] : a[0]) ins(x);
    rep(i, 0, SZ(a[3])) {
        if(k >= i && k - i < SZ(a[1])) t = a[1][k - i].first, su -= t, ins(t);
        if(k >= i && k - i < SZ(a[2])) t = a[2][k - i].first, su -= t, ins(t);
        if(k - i <= min({SZ(a[1]), SZ(a[2])})) upd(m - i - 2 * max(k - i, 0), i);
        if(i < SZ(a[3])) su += a[3][i].first;
    }
    if(as == INT_MAX) puts("-1"), exit(0);
    cout << as << endl;
    For(i, 0, K) printf("%d ", a[3][i].second);
    For(i, 0, k - K) printf("%d %d ", a[1][i].second, a[2][i].second);
    For(i, max(0, k - K), SZ(a[1])) a[0].pb(a[1][i]);
    For(i, max(0, k - K), SZ(a[2])) a[0].pb(a[2][i]);
    sort(a[0].begin(), a[0].end());
    For(i, 0, m - K - 2 * max(k - K, 0)) printf("%d ", a[0][i].second);
}