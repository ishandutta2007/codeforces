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

int N, cnt1, cnt_1;
string S, src;
vector<string> ans, cons;
map<string, int> indeg, outdeg;
map<string, vector<string> > adj;

void dfs(string n) {
	while (adj[n].size()) {
		string u = adj[n].back();
		adj[n].ppb();
		dfs(u);
	}
	ans.pb(n);
}

void cannot() {
	cout << "NO\n";
	exit(0);
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> S;
		adj[S.substr(0, 2)].pb(S.substr(1, 2));
		outdeg[S.substr(0, 2)]++;
		indeg[S.substr(1, 2)]++;
		cons.pb(S.substr(0, 2));
		cons.pb(S.substr(1, 2));
	}
	sort(cons.begin(), cons.end());
	cons.erase(unique(cons.begin(), cons.end()), cons.end());
	for (auto i : cons) {
		if (llabs(indeg[i] - outdeg[i]) >= 2) cannot();
		if (indeg[i] - outdeg[i] == -1) src = i;
		cnt1 += (indeg[i] - outdeg[i] == 1);
		cnt_1 += (indeg[i] - outdeg[i] == -1);
	}
	if (cnt1 != cnt_1 || cnt1 > 1) cannot();
	if (src == "") src = adj.begin()->first;
	dfs(src);
	for (auto i : cons)
		if (adj[i].size()) cannot();
	reverse(ans.begin(), ans.end());
	cout << "YES\n" << ans[0][0];
	for (auto i : ans) cout << i.back();
	cout << '\n';
}