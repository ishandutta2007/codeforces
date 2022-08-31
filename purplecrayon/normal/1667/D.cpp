#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

int n, par[N];
bool dp[N][5]; // E - O + 2
vector<int> adj[N];
bool par_ev[N], par_odd[N];
bool choose_ev[N];

int deg(int v) {
    return sz(adj[v]);
}
bool good(int c, int delta) {
    if (delta < 0 && deg(c) % 2 == 0) return 0;
    if (delta > 0 && deg(c) % 2) return 0;
    return abs(delta) <= 1;
}
void rec(int c, int p) {
    par[c] = p;
    memset(dp[c], 0, sizeof(dp[c]));

    int must = 0, both = 0;
    for (auto nxt : adj[c]) if (nxt != p) {
        rec(nxt, c);

        bool ev = 0, odd = 0;
        for (int d = -2; d <= 2; d++) {
            ev |= dp[nxt][d + 2] && good(nxt, d + 1);
            odd |= dp[nxt][d + 2] && good(nxt, d - 1);
        }
        par_ev[nxt] = ev, par_odd[nxt] = odd;
        // cerr << "> " << c << ' ' << nxt << ' ' << ev << ' ' << odd << '\n';
        if (ev && odd) both++;
        else if (ev) must++;
        else if (odd) must--;
        else {
            return;
        }
    }

    // possible delta: {must - both, must + both}
    int L = max(-2, must - both), R = min(+2, must + both);
    // cerr << c << ' ' << L << ' ' << R << '\n';
        // cerr << L << ' ' << R << '\n';
    for (int i = L; i <= R; i++) if (((i % 2) + 2) % 2 == (((must + both) % 2) + 2) % 2) {
        dp[c][i + 2] = true;
    }
}
void build(int c, int p, int d) { // delta passed from parent
    int must = 0;
    int both = 0;
    for (auto nxt : adj[c]) if (nxt != p) {
        if (!par_ev[nxt]) {
            choose_ev[nxt] = false;
            build(nxt, c, -1);
            must--;
        } else if (!par_odd[nxt]) {
            choose_ev[nxt] = true;
            build(nxt, c, +1);
            must++;
        } else {
            both++;
        }
    }
    int L = max(-2, must - both), R = min(+2, must + both);
    // cerr << L << ' ' << R << '\n';
    int use = MOD;
    for (int i = L; i <= R; i++) if (((i % 2) + 2) % 2 == (((must + both) % 2) + 2) % 2) {
        if (good(c, i + d) && dp[c][i + 2]) {
            use = i;
        }
    }
    assert(use != MOD);
    // must + x - (both - x) = use
    // must - both + 2*x = use
    // x = (use - must + both) / 2
    
    int use_ev = (use - must + both) / 2;
    int use_odd = both - use_ev;

    for (auto nxt : adj[c]) if (nxt != p && par_odd[nxt] && par_ev[nxt]) {
        if (use_ev) {
            choose_ev[nxt] = true;
            build(nxt, c, -1);
            use_ev--;
        } else {
            choose_ev[nxt] = false;
            build(nxt, c, +1);
            use_odd--;
        }
    }
    assert(use_ev == 0 && use_odd == 0);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) adj[i].clear();
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);
    }

    // assign E and O to each edge so that every node has the appropriate number of adjacent E/O things
    // dp[subtree][delta]
    // calculate E's and O's, simulate deletion

    rec(0, -1);
    bool bad = 1;
    for (int d = -2; d <= 2; d++) if (good(0, d) && dp[0][d + 2]) {
        bad = 0;
    }
    if (bad) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    build(0, -1, 0);

    vector<vector<int>> top(n);
    for (int c = 0; c < n; c++) {
        vector<int> ev, odd;
        for (int nxt : adj[c]) {
            if (nxt == par[c]) {
                if (choose_ev[c]) ev.push_back(c);
                else odd.push_back(c);
            } else {
                if (choose_ev[nxt]) ev.push_back(nxt);
                else odd.push_back(nxt);
            }
        }
        vector<int> ord;
        // cerr << sz(odd) << ' ' << sz(ev) << '\n';

        int cur = deg(c) % 2;
        int p1 = 0, p2 = 0;
        for (int rep = 0; rep < sz(adj[c]); rep++) {
            if (cur == 0) ord.push_back(ev[p1++]);
            else ord.push_back(odd[p2++]);
            cur ^= 1;
        }

        for (int i = 1; i < sz(ord); i++) {
            assert(ord[i] && ord[i-1]);
            top[ord[i-1]].push_back(ord[i]);
        }
    }

    vector<int> in(n);
    for (int i = 1; i < n; i++)
        for (int j : top[i])
            in[j]++;

    vector<int> q; q.reserve(n);
    for (int i = 1; i < n; i++) if (in[i] == 0)
        q.push_back(i);

    for (int rep = 0; rep < sz(q); rep++) {
        int c = q[rep];
        for (int nxt : top[c]) if ((--in[nxt]) == 0) {
            q.push_back(nxt);
        }
    }
    assert(sz(q) == n-1);
    for (int x : q) cout << par[x]+1 << ' ' << x+1 << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}