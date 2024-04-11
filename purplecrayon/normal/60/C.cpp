#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e2+10, MOD = 998244353;
const int MAXM = 1e4+10;

const int MAXV = 2e6+10;
int pf[MAXV];

void pre() {
    memset(pf, -1, sizeof(pf));
    for (int i = 2; i < MAXV; i++) if (pf[i] == -1) {
        for (int j = i; j < MAXV; j+=i) pf[j] = i;
    }
}
vector<pair<int, int>> get_pf(int n) {
    vector<pair<int, int>> r;
    int c=n;
    while (c > 1){
        int v = pf[c];
        r.emplace_back(v, 0);
		while (c%v == 0) r.back().second++, c /= v;
    }
    return r;
}


int n, m;
ar<int, 4> e[MAXM];
vector<ar<int, 3>> adj[MAXN];
int ans[MAXN];

void NO() {
    cout << "NO\n";
    exit(0);
}
void YES() {
    cout << "YES\n";
    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << '\n';
    exit(0);
}

int po(int b, int p) {
    int r = 1;
    for (; p; p >>= 1, b *= b) if (p & 1) r *= b;
    return r;
}
int get_cnt(int x, int p) {
    int ans = 0;
    while (x % p == 0) ans++, x /= p;
    return ans;
}
void reset(int c) {
    ans[c] = -1;
    for (auto [nxt, _, __] : adj[c]) if (ans[nxt] != -1) reset(nxt);
}

bool dfs(int c) {
    int me = ans[c];
    assert(me != -1);
    for (auto [nxt, g, l] : adj[c]) {
        int x = 1;
        for (auto [p, two] : get_pf(l)) {
            int one = get_cnt(g, p), k = get_cnt(me, p);
            if (one != k) swap(one, two);
            if (one != k) return 0;
            x *= po(p, two);
        }
        if (ans[nxt] == -1) {
            ans[nxt] = x;
            if (!dfs(nxt))
                return 0;
        } else {
            if (ans[nxt] != x) return 0;
        }
    }
    return 1;
}
void solve() {
    pre();

    cin >> n >> m;
    int M = 1;
    for (int i = 0; i < m; i++) {
        int a, b, g, l; cin >> a >> b >> g >> l, --a, --b;
        e[i] = {a, b, g, l};
        adj[a].push_back({b, g, l}), adj[b].push_back({a, g, l});
        if (l % g) NO();

        M = max(M, l);
    }
    memset(ans, -1, sizeof(ans));

    for (int i = 0; i < n; i++) if (ans[i] == -1) {
        if (!sz(adj[i])) {
            ans[i] = 1;
            continue;
        }
        ar<int, 3> test{i, adj[i][0][2], adj[i][0][1]};

        vector<ar<int, 2>> v;
        for (auto [c, one] : get_pf(test[1])) {
            int two = get_cnt(test[2], c);
            v.push_back({po(c, one), po(c, two)});
        }
        
        int N = sz(v);
        bool bad = 1;
        for (int i = 0; i < (1 << N); i++) {
            reset(test[0]);
            ans[test[0]] = 1;
            for (int j = 0; j < N; j++) ans[test[0]] *= v[j][(i >> j) & 1];
            if (dfs(test[0])) {
                bad = 0;
                break;
            }
        }
        if (bad) NO();
    }
    YES();
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}