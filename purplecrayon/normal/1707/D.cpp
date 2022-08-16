#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e3+10, MOD = 1e9+7;

int M;

int add_self(int& a, int b) {
    a += b;
    if (a >= M) a -= M;
    return a;
}
int add(int a, int b) {
    return add_self(a, b);
}
int sub_self(int& a, int b) {
    a -= b;
    if (a < 0) a += M;
    return a;
}
int sub(int a, int b) {
    return sub_self(a, b);
}
int mul(int a, int b) {
    return (long long) a * b % M;
}
void mul_self(int& a, int b) {
    a = mul(a, b);
}
int po(int b, int p) {
    int r = 1;
    for (; p; b = mul(b, b), p >>= 1) if (p&1) mul_self(r, b);
    return r;
}
int inv(int x) {
    return po(x, M-2);
}
int di(int a, int b) {
    return mul(a, inv(b));
}
int di_self(int a, int b) {
    return a = di(a, b);
}


const int V = 2 * N;
int fact[V], ifact[V];

int nck(int n, int k) {
    return mul(fact[n], mul(ifact[k], ifact[n-k]));
}

int n, K, sub_sz[N];
vector<int> adj[N];
int dp[N][N], delta[N][N];

void dfs(int c, int p) {
    // dp[c][k] -> every removal time assigned is <= k
    for (auto nxt : adj[c]) if (nxt != p) dfs(nxt, c);
    if (p == -1) {
        vector<int> cdp(K, 1);
        for (auto nxt : adj[c]) if (nxt != p) {
            for (int i = 0; i < K; i++) {
                mul_self(cdp[i], dp[nxt][i]);
            }
        }
        for (int k = 1; k <= K; k++) {
            int ans = 0;
            for (int z = 0; z < k; z++) {
                int cur_mul = z % 2 == 0 ? +1 : M-1;
                mul_self(cur_mul, nck(k, z));
                add_self(ans, mul(cur_mul, cdp[k-1-z]));
            }
            cout << ans << ' ';
        }
        cout << '\n';
        return;
    }
    auto upd = [&](int c, int L, int R, int x) {
        if (L > R) return;
        add_self(delta[c][L], x);
        sub_self(delta[c][R+1], x);
    };

    adj[c].erase(find(adj[c].begin(), adj[c].end(), p));
    for (int me = 0; me < K; me++) {
        // int no_big = 1;
        int deg = sz(adj[c]);
        vector<int> pre(deg);
        vector<int> suf(deg);
        for (int i = 0; i < deg; i++) {
            int nxt = adj[c][i];
            pre[i] = dp[nxt][me];
            suf[i] = dp[nxt][me];
        }
        for (int i = 1; i < deg; i++) mul_self(pre[i], pre[i-1]);
        for (int i = deg-2; i >= 0; i--) mul_self(suf[i], suf[i+1]);

        // for (auto nxt : adj[c]) if (nxt != p) {
            // mul_self(no_big, dp[nxt][me]);
        // }
        add_self(dp[c][me], (deg == 0 ? 1 : pre.back()));
        // add_self(dp[c][me], no_big);
        for (int i = 0; i < deg; i++) {
        // for (auto nxt : adj[c]) if (nxt != p) {
            int nxt = adj[c][i];
            int cur = 1;
            if (i) mul_self(cur, pre[i-1]);
            if (i < deg-1) mul_self(cur, suf[i+1]);
            upd(nxt, me + 1, K - 1, cur);
            // upd(nxt, me + 1, K - 1, di(no_big, dp[nxt][me]));
        }
        /*
        for (auto nxt : adj[c]) if (nxt != p) {
            for (int he = me + 1; he < K; he++) {
                add_self(dp[c][he], mul(di(no_big, dp[nxt][me]), sub(dp[nxt][he], dp[nxt][he-1])));
            }
        }
        */
    }
    for (int i = 1; i < K; i++) {
        for (auto nxt : adj[c]) if (nxt != p) {
            add_self(delta[nxt][i], delta[nxt][i-1]);
            add_self(dp[c][i], mul(delta[nxt][i], sub(dp[nxt][i], dp[nxt][i-1])));
        }
    }
    for (int me = 1; me < K; me++) add_self(dp[c][me], dp[c][me-1]);
}
void solve() {
    cin >> n >> M;
    K = n-1;
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }

    fact[0] = ifact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = mul(fact[i-1], i), ifact[i] = inv(fact[i]);

    dfs(0, -1);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}