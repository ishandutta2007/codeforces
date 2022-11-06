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
typedef double db;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, QU, idx, ord[300005], match[300005], par[300005], val[300005], pval[300005];
bool in[300005], vis[300005];
char S[300005];
vector<int> adj[300005], pval2[300005];
stack<int> st;
queue<int> Q;
set<int> cl;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> QU;
	for (int i = 1; i <= N; i++) {
		cin >> S[i];
		if (S[i] == '(') {
			st.push(i);
		} else {
			if (st.empty()) continue;
			match[i] = st.top();
			match[st.top()] = i;
			st.pop();
		}
	}
	//for (int i = 1; i <= N; i++) cout << match[i] << ' ';
	//cout << '\n';
	for (int i = 1; i <= N; i++)
		if (match[i] && match[i] < i) {
			vector<set<int>::iterator> todel;
			auto it = cl.lower_bound(match[i]);
			while (it != cl.end() && *it < i) {
				in[*it] = 1;
				adj[i].pb(*it);
				todel.pb(it);
				++it;
			}
			cl.insert(i);
			for (auto j : todel) cl.erase(j);
		}
	for (int i = 1; i <= N; i++) {
		sort(adj[i].begin(), adj[i].end());
		if (match[i] && match[i] < i) {
			if (!in[i]) {
				adj[N + 1].pb(i);
				in[i] = 1;
			}
		}
	}
	Q.push(N + 1);
	vis[N + 1] = match[N + 1] = 1;
	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();
		for (auto u : adj[x]) {
			if (vis[u]) continue;
			par[u] = x;
			Q.push(u);
			vis[u] = 1;
		}
	}
	for (int i = 1; i <= N + 1; i++) {
		if (match[i] && match[i] < i && par[i]) val[i] = lower_bound(adj[par[i]].begin(), adj[par[i]].end(), i) - adj[par[i]].begin() + 1;
		pval[i] = val[i] + pval[i - 1];
	}
	for (int i = 1; i <= N + 1; i++) {
		if (!match[i]) continue;
		pval2[i].resize(adj[i].size());
		for (int j = 0; j < adj[i].size(); j++) {
			pval2[i][j] = (j ? pval2[i][j - 1] : 0) + val[adj[i][j]];
			//cout << "PVAL2 " << i << ' ' << j << ' ' << pval2[i][j] << '\n';
		}
	}
	for (int t, l, r; QU--; ) {
		cin >> t >> l >> r;
		//cout << par[r] << '\n';
		auto it = lower_bound(adj[par[r]].begin(), adj[par[r]].end(), r) - adj[par[r]].begin();
		auto it2 = lower_bound(adj[par[r]].begin(), adj[par[r]].end(), l) - adj[par[r]].begin();
		//cout << it << ' ' << it2 << '\n';
		cout << pval[r] - pval[l - 1] - (pval2[par[r]][it] - (it2 ? pval2[par[r]][it2 - 1] : 0)) + (it - it2 + 1) * (it - it2 + 2) / 2 << '\n';
	}
}