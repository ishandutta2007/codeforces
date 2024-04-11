#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define eb emplace_back

using namespace std;

const int N = 2e5 + 5;

int n, m, sz, en[N], ch[N][26], f[N], q[N];
int idx, dl[N], dr[N], c[N], ans[N * 5 / 2];
vector<int> G[N];
vector<tuple<int, int, int>> Q[N];
string s[N];

void dfs(int u) {
    dl[u] = ++idx;
    for(int v : G[u]) dfs(v);
    dr[u] = idx;
}
void add(int i) {
    for(; i <= idx; i += i & -i) c[i]++;
}
int qry(int i, int r = 0) {
    for(; i; i &= i - 1) r += c[i];
    return r;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    rep(i, 1, n) {
        cin >> s[i];
        int o = 0;
        for(int c : s[i]) {
            int& O = ch[o][c - 97];
            if(!O) O = ++sz;
            o = O;
        }
        en[i] = o;
    }
    int l, r, k;
    rep(i, 1, m) {
        cin >> l >> r >> k;
        Q[r].eb(en[k], i, 1), Q[--l].eb(en[k], i, -1);
    }
    l = 1, r = 0;
    rep(i, 0, 25) if(ch[0][i]) q[++r] = ch[0][i];
    while(l <= r) {
        int u = q[l++];
        rep(i, 0, 25) {
            int& v = ch[u][i];
            (v ? f[q[++r] = v] : v) = ch[f[u]][i];
        }
    }
    rep(i, 1, sz) G[f[i]].pb(i);
    dfs(0);
    rep(i, 1, n) {
        int o = 0;
        for(int c : s[i]) {
            o = ch[o][c - 97];
            add(dl[o]);
        }
        for(auto [k, id, v] : Q[i])
            ans[id] += v * (qry(dr[k]) - qry(dl[k] - 1));
    }
    rep(i, 1, m) cout << ans[i] << '\n';
}