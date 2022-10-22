#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define eb emplace_back
#pragma GCC target("bmi")

using namespace std;
using ll = long long;

const int N = 3e5 + 5;

int n, q, x[N], w[N], L[N], R[N];
ll c[N], ans[N];
vector<pair<int, ll>> qs[N], op[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    rep(i, 1, n) {
        cin >> x[i] >> w[i];
        for(int& j = L[i] = i - 1; j && w[j] > w[i]; R[j] = i, j = L[j]);
    }
    mem(c, 63), mem(ans, 63);
    int l, r;
    rep(i, 1, q) cin >> l >> r, qs[l].eb(r, i);
    per(i, n, 1) {
        if(L[i]) op[L[i]].eb(i, ll(x[i] - x[L[i]]) * (w[i] + w[L[i]]));
        if(R[i]) op[i].eb(R[i], ll(x[R[i]] - x[i]) * (w[i] + w[R[i]]));
        for(auto [r, v] : op[i]) for(; r <= n; r += r & -r) c[r] = min(c[r], v);
        for(auto [r, i] : qs[i]) for(; r; r &= r - 1) ans[i] = min(ans[i], c[r]);
    }
    rep(i, 1, q) cout << ans[i] << '\n';
}