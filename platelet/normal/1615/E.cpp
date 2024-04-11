#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = long long;

const int N = 2e5 + 5;

int n, k, len[N], idx;
vector<int> G[N];

int dfs(int u, int fa) {
    int res = 0;
    for(int v : G[u]) if(v != fa) {
        int l = dfs(v, u);
        if(l > res) swap(l, res);
        len[++idx] = l;
    }
    return res + 1;
}

int main() {
    cin >> n >> k;
    int u, v;
    rep(i, 2, n) scanf("%d%d", &u, &v), G[u].pb(v), G[v].pb(u);
    len[n] = dfs(1, 0);
    sort(len + 1, len + n + 1, greater<int>());
    partial_sum(len, len + n + 1, len);
    ll ans = -1e18;
    rep(i, 0, k) {
        ll x = min(n - len[i], n >> 1);
        ans = max(ans, (x - n + i) * (x - i));
    }
    cout << ans;
}