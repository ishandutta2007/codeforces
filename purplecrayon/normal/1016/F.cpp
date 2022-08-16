#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3e5+10, MOD = 1e9+7;
const ll INF = 1e15+10;

#include<bits/extc++.h>
struct splitmix64_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
template <typename K, typename V, typename Hash = splitmix64_hash>
using hash_map = __gnu_pbds::gp_hash_table<K, V, Hash>;
template <typename K, typename Hash = splitmix64_hash>
using hash_set = hash_map<K, __gnu_pbds::null_type, Hash>;

// the query doesn't matter, you'll always add the same edge
// maximize d_1[u] + d_n[v]

int n, m, et[MAXN];
ll dist[2][MAXN];
vector<pair<int, ll>> adj[MAXN];

#warning hash_set?
set<int> edge[MAXN];

bool has_edge(int a, int b) {
    return edge[a].find(b) != edge[a].end();
}
void dfs(int c, int p, ll d, int b) {
    dist[b][c] = d;
    for (auto [nxt, x] : adj[c]) if (nxt != p) {
        dfs(nxt, c, d + x, b);
    }
}
bool dfs_reord(int c, int p) {
    vector<pair<bool, pair<int, ll>>> ch;
    bool ret = 0;
    for (auto [nxt, x] : adj[c]) if (nxt != p) {
        bool v = dfs_reord(nxt, c);
        ch.emplace_back(v, make_pair(nxt, x));

        ret |= v;
    }
    sort(ch.begin(), ch.end());
    adj[c].clear();
    for (auto [_, x] : ch) adj[c].push_back(x);

    return ret || (c == n - 1);
}

int tt = 0;
void dfs_ord(int c, int p) {
    et[tt++] = c;
    for (auto [nxt, x] : adj[c]) if (nxt != p)
        dfs_ord(nxt, c);
}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) edge[i].insert(i);
    for (int i = 0; i < n-1; i++) {
        int a, b; ll c; cin >> a >> b >> c, --a, --b;

        edge[a].insert(b), edge[b].insert(a);
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    dfs(0, -1, 0, 0);
    dfs(n-1, -1, 0, 1);

    dfs_reord(0, -1);
    dfs_ord(0, -1);

    // for (int i = 0; i < n; i++) cerr << et[i] << ' '; cerr << endl;

    set<pair<ll, int>> big;
    pair<ll, pair<int, int>> best{-1, {-1, -1}};
    for (int i = n-1; i >= 0; i--) {
        int c = et[i];
        for (auto it = big.end(); it != big.begin(); ) {
            it = prev(it);
            if (has_edge(c, it->second)) continue;
            // cerr << c << ' ' << (it->second) << endl;
            best = max(best, make_pair(dist[0][c] + it->first, make_pair(c, it->second)));
            break;
        }
        big.insert({dist[1][c], c});
    }

    pair<int, int> c = best.second;

    while (m--) {
        ll x; cin >> x;
        ll ans = min({dist[0][n-1], dist[0][c.first] + dist[1][c.second] + x, dist[0][c.second] + dist[1][c.first] + x});
        cout << ans << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}