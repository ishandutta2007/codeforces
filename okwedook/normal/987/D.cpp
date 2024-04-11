#pragma GCC optimize("O3","unroll-loops")
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-9
#define mod 1000000007
#define inf 1000000000000000007ll
#define intinf ((1 << 31) - 1)
#define f first
#define s second

#include <bits/stdc++.h>
using namespace std;

template<typename T1, typename T2> inline void checkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2> inline void checkmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1> inline void sort(T1 &arr) { sort(arr.begin(), arr.end()); }
template<typename T1> inline void shuffle(T1 &arr) { 
    for (int i = -arr.size(); i < arr.size(); ++i) {
        int f = ((rand() << 16) + rand()) % arr.size(), s = ((rand() << 16) + rand()) % arr.size();
        swap(arr[f], arr[s]);
    }
}
template<typename T1> inline void reverse(T1 &arr) { reverse(arr.begin(), arr.end()); }
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> graph;

const ll N = 100000;

bool used[N][101];
int depth[N][101];
graph G;

struct node {
	int ind, depth, color;
	node() {}
	node(int a, int b, int c) {
		ind = a;
		depth = b;
		color = c;
	}
};

signed main() {
	FAST;
	int n, m, s, k;
	cin >> n >> m >> k >> s;
	vector<ll> a(n);
	G = graph(n);
	for (auto &i : a) cin >> i;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		G[u].pb(v);
		G[v].pb(u);
	}
	deque<node> bfs;
	for (int i = 0; i < n; ++i) bfs.pb(node(i, 0, a[i]));
	while (bfs.size() > 0) {
		node p = bfs.front();
		bfs.popf();
		if (used[p.ind][p.color]) continue;
		used[p.ind][p.color] = true;
		depth[p.ind][p.color] = p.depth;
		for (auto i : G[p.ind])
			if (!used[i][p.color]) bfs.pb(node(i, p.depth + 1, p.color)), used[i][p.color];
	}
	for (int i = 0; i < n; ++i) {
		ll ans = 0;
		sort(depth[i] + 1, depth[i] + k + 1);
		for (int j = 1; j <= s; ++j) ans += depth[i][j];
		cout << ans << ' ';
	}
    return 0;
}