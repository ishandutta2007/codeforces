#pragma GCC optimize("O3","unroll-loops")
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(2)
#define pb push_back
#define pf pop_front
#define popb pop_back
#define popf pop_front
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-8
#define mod 1000000009
#define inf 1000000000000000007ll
#define intinf ((1 << 31) - 1)
#define f first
#define s second

#include <bits/stdc++.h>
using namespace std;

template<typename T1, typename T2> inline void checkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2> inline void checkmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1> inline void sort(T1 &arr) { sort(arr.begin(), arr.end()); }
template<typename T1> inline void reverse(T1 &arr) { reverse(arr.begin(), arr.end()); }
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> graph;

graph G;
vector<bool> fused;
vector<bool> sused;
ll cnt = 0;
bool flag = true;

void dfscnt(ll v) {
	++cnt;
	fused[v] = true;
	for (auto i : G[v]) 
		if (!fused[i]) 
			dfscnt(i);
}

void dfs(ll v) {
	sused[v] = true;
	flag = flag && G[v].size() == 2;
	for (auto i : G[v]) 
		if (!sused[i]) 
			dfs(i);
}

int main() {
	FAST;
	ll n, m;
	cin >> n >> m;
	G = graph(n);
	sused = fused = vector<bool>(n);
	for (int i = 0; i < m; ++i) {
		ll u, v;
		cin >> u >> v;
		--u, --v;
		G[u].pb(v);
		G[v].pb(u);
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i) 
		if (!sused[i]) {
			cnt = 0;
			flag = true;
			dfscnt(i);
			if (cnt < 2) flag = false;
			dfs(i);
			if (flag) ++ans;
		}
	cout << ans;
    return 0;
}