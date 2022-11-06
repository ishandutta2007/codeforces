#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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
typedef double db;
typedef long double ld;
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, total, A[200005];
vector<int> adj[200005], cnt0[200005], cnt1[200005];

void dfs(int n, int e = -1) {
	for (auto u : adj[n])
		if (u != e) {
			A[u] = min(A[u], A[n]);
			dfs(u, n);
			if (cnt0[u].size() > cnt0[n].size()) swap(cnt0[u], cnt0[n]);
			for (int i : cnt0[u]) cnt0[n].pb(i);
			if (cnt1[u].size() > cnt1[n].size()) swap(cnt1[u], cnt1[n]);
			for (int i : cnt1[u]) cnt1[n].pb(i);
		}
	while (!cnt0[n].empty() && !cnt1[n].empty()) {
		cnt0[n].ppb();
		cnt1[n].ppb();
		total += A[n] * 2;
	}
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1, B, C; i <= N; i++) {
		cin >> A[i] >> B >> C;
		if (B > C) cnt1[i].pb(i);
		else if (C > B) cnt0[i].pb(i);
	}
	for (int i = 1, u, v; i < N; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1);
	cout << (cnt0[1].size() || cnt1[1].size() ? -1 : total) << '\n';
}