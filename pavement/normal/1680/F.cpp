#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define g0(a) get<0>(a)
#define g1(a) get<1>(a)
#define g2(a) get<2>(a)
#define g3(a) get<3>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using db = double;
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using iiii = tuple<int, int, int, int>;
template<class key, class value = null_type, class cmp = less<key> >
using ordered_set = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

int T, N, M, ans, U[1000005], V[1000005], rdep[1000005], par[1000005], gcnt[1000005], bcnt[1000005];
bool inv, vis[1000005], dep[1000005];
vector<int> bad, good, adj[1000005], adj2[1000005];

void dfs(int n) {
	for (auto u : adj[n]) if (!vis[u]) {
		vis[u] = 1;
		adj2[n].pb(u);
		adj2[u].pb(n);
		dfs(u);
	}
}

void dfs2(int n, int e = -1) {
	par[n] = e;
	for (auto u : adj2[n]) if (u != e) {
		rdep[u] = rdep[n] + 1;
		dep[u] = dep[n] ^ 1;
		dfs2(u, n);
	}
}

ii dfs3(int n, int e = -1) {
	ii tmp = mp(gcnt[n], bcnt[n]);
	for (auto u : adj2[n]) if (u != e) {
		auto curr = dfs3(u, n);
		tmp.first += curr.first;
		tmp.second += curr.second;
	}
	if (n != 1 && tmp.second == bad.size() && tmp.first == 1) ans = n;
	return tmp;
}

void dfs4(int n, int e = -1) {
	dep[n] ^= 1;
	for (auto u : adj2[n]) if (u != e)
		dfs4(u, n);
}

void reset() {
	for (int i = 1; i <= N; i++) {
		U[i] = V[i] = rdep[i] = par[i] = gcnt[i] = bcnt[i] = 0;
		vis[i] = dep[i] = 0;
		adj[i].clear();
		adj2[i].clear();
	}
	ans = inv = 0;
	bad.clear();
	good.clear();
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		for (int i = 1; i <= M; i++) {
			cin >> U[i] >> V[i];
			adj[U[i]].pb(V[i]);
			adj[V[i]].pb(U[i]);
		}
		vis[1] = 1;
		dfs(1);
		dfs2(1);
		for (int i = 1; i <= M; i++)
			if (dep[U[i]] == dep[V[i]]) bad.pb(i);
			else good.pb(i);
		if (bad.size() <= 1) {
			cout << "YES\n";
			for (int i = 1; i <= M; i++)
				if (!dep[U[i]] && !dep[V[i]]) inv = 1;
			if (inv) {
				for (int i = 1; i <= N; i++) dep[i] ^= 1;
			}
			for (int i = 1; i <= N; i++) cout << dep[i];
			cout << '\n';
			reset();
			continue;
		}
		for (auto i : bad) {
			if (rdep[U[i]] > rdep[V[i]]) swap(U[i], V[i]);
			bcnt[U[i]]--;
			bcnt[V[i]]++;
		}
		for (auto i : good) {
			if (rdep[U[i]] > rdep[V[i]]) swap(U[i], V[i]);
			gcnt[U[i]]--;
			gcnt[V[i]]++;
		}
		ans = -1;
		dfs3(1);
		if (ans == -1) {
			cout << "NO\n";
			reset();
			continue;
		}
		dfs4(ans, par[ans]);
		cout << "YES\n";
		for (int i = 1; i <= M; i++)
			if (!dep[U[i]] && !dep[V[i]]) inv = 1;
		if (inv) {
			for (int i = 1; i <= N; i++) dep[i] ^= 1;
		}
		for (int i = 1; i <= N; i++) cout << dep[i];
		cout << '\n';
		reset();
	}
}