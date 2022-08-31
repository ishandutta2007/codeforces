#include "bits/stdc++.h"
using namespace std;

template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 5e5+10, MAXM = 40, MAXL = 20, ALP = 20, MOD = 998244353, MAXK = 17, INF = 1e9+10, MAXA = 1e2+10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

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

int n, m, col[MAXN], d[MAXN];
vector<ar<int, 2>> badj[MAXN];
hash_set<int> adj[MAXN][2];
bool vis[MAXN];

void solve(){
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c, --a, --b;
        adj[a][c].insert(b); badj[b].push_back({a, c});
    }
    memset(col, -1, sizeof(col));
    col[n-1] = rand()%2; //to illustrate that it doesn't matter
    queue<int> q; q.push(n-1);

    auto has_edge = [&](int from, int to, int color) {
        return adj[from][color].find(to) != adj[from][color].end();
    };

    memset(vis, 0, sizeof(vis));
    while (sz(q)) {
        int c=q.front(); q.pop();
        for (auto nxt : badj[c]) {
            if (col[nxt[0]] == -1) { //has been visited by something with smaller distance
                int bad_col = nxt[1]; 
                col[nxt[0]] = bad_col ^ 1;
            }

            if (!vis[nxt[0]] && has_edge(nxt[0], c, col[nxt[0]])) {
                q.push(nxt[0]);
                vis[nxt[0]] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) col[i] = max(col[i], 0);

    fill(d, d+n, INF);
    d[n-1] = 0, q.push(n-1);
    while (sz(q)) {
        int c=q.front(); q.pop();
        for (auto nxt : badj[c]) if (nxt[1] == col[nxt[0]] && d[nxt[0]] == INF) {
            d[nxt[0]] = d[c]+1;
            q.push(nxt[0]);
        }
    }
    cout << (d[0] == INF ? -1 : d[0]) << '\n';
    for (int i = 0; i < n; i++) cout << max(0, col[i]);
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}