#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef TEST
#define getchar_unlocked _getchar_nolock
#endif
#define int long long
#define ins insert
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define pp pop
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define g0(a) get<0>(a)
#define g1(a) get<1>(a)
#define g2(a) get<2>(a)
#define g3(a) get<3>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long double ld;
typedef long long ll;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, M, S, idx, cn = 1, re, tt, rin[5005], link[5005], sz[5005], link2[5005], sz2[5005], cnt[5005], ol[5005];
bool inc[5005], in[5005];
vector<int> adj[5005];
stack<int> st;

int find(int x) {
	if (x == link[x]) return x;
	return link[x] = find(link[x]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (sz[b] > sz[a]) swap(a, b);
	sz[a] += sz[b];
	cnt[a] += cnt[b];
	link[b] = a;
}

int find2(int x) {
	if (x == link2[x]) return x;
	return link2[x] = find2(link2[x]);
}

void unite2(int a, int b) {
	a = find2(a);
	b = find2(b);
	if (a == b) return;
	if (sz2[b] > sz2[a]) swap(a, b);
	sz2[a] += sz2[b];
	link2[b] = a;
}

void dfs(int n) {
	bool ro = 1;
	rin[n] = ++idx;
	for (auto u : adj[n]) {
		if (rin[u] == -1) dfs(u);
		if (!inc[u] && rin[u] < rin[n])
			rin[n] = rin[u], ro = 0;
	}
	if (ro) {
		vector<int> v;
		inc[n] = 1;
		v.pb(n);
		while (!st.empty() && rin[n] <= rin[st.top()]) {
			int w = st.top();
			st.pop();
			rin[w] = cn;
			inc[w] = 1;
			v.pb(w);
		}
		rin[n] = cn;
		sort(v.begin(), v.end());
		for (auto i : v)
			for (auto j : adj[i])
				if (!binary_search(v.begin(), v.end(), j)) {
					unite(rin[i], rin[j]);
					in[rin[j]] = 1;
				}
		cn++;
	} else st.push(n);
}

void dfs2(int n) {
	if (inc[n]) return;
	inc[n] = 1;
	re++;
	for (auto u : adj[n])
		dfs2(u);
}

main() {
	memset(rin, -1, sizeof rin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> S;
	for (int i = 1; i <= N; i++) {
		link[i] = link2[i] = i;
		sz[i] = sz2[i] = 1;
	}
	for (int u, v; M--; ) {
		cin >> u >> v;
		unite2(u, v);
		adj[u].pb(v);
		ol[v]++;
	}
	for (int i = 1; i <= N; i++)
		if (rin[i] == -1) dfs(i);
	cn--;
	for (int i = 1; i <= cn; i++)
		cnt[find(i)] += !in[i];
	memset(inc, 0, sizeof inc);
	for (int i = 1; i <= cn; i++) {
		if (inc[find(i)]) continue;
		inc[find(i)] = 1;
		tt += max(1ll, cnt[find(i)]);
	}
	memset(inc, 0, sizeof inc);
	dfs2(S);
	cout << tt - (ol[S] == 0 || re == sz2[find2(S)]) << '\n';
}