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
#define pf push_front
#define ppb pop_back
#define ppf pop_front
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

int T, N, p, curcnt, curr, aval, vval, idx, A[200005], dep[200005], dp[200005], par[200005];
vector<int> adj[200005], vec[200005];
vector<iii> tmp3;
bool vis[200005];

void dfs(int n, int e = -1) {
	assert(!vis[n]);
	par[n] = e;
	vis[n] = 1;
	for (auto u : adj[n]) {
		if (u == e) continue;
		dep[u] = dep[n] + 1;
		dfs(u, n);
	}
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N;
		for (int i = 2; i <= N; i++) {
			cin >> p;
			adj[i].pb(p);
			adj[p].pb(i);
		}
		for (int i = 2; i <= N; i++) cin >> A[i];
		dfs(1);
		int tmp = 0;
		for (int i = 1; i <= N; i++)
			vec[dep[i]].pb(i), tmp = max(tmp, dep[i]);
		for (int i = tmp; i >= 0; i--) {
			if (i == tmp) {
				int minval = LLONG_MAX, maxval = LLONG_MIN;
				for (int j : vec[i])
					minval = min(minval, A[j]), maxval = max(maxval, A[j]);
				for (int j : vec[i])
					dp[j] = max(llabs(A[j] - minval), llabs(A[j] - maxval));
			} else {
				tmp3.clear();
				int minval = LLONG_MAX, maxval = LLONG_MIN;
				for (int j : vec[i])
					minval = min(minval, A[j]), maxval = max(maxval, A[j]);
				for (int j : vec[i]) {
					int v = 0;
					for (int k : adj[j])
						if (k != par[j]) v = max(v, dp[k]);
					dp[j] = max(llabs(A[j] - minval), llabs(A[j] - maxval)) + v;
					tmp3.eb(A[j], v, j);
				}
				sort(tmp3.begin(), tmp3.end());
				curcnt = 0, curr = LLONG_MIN;
				stack<int> S;
				for (auto j : tmp3) {
					tie(aval, vval, idx) = j;
					curr = max(curr, -aval + vval);
					S.push(idx);
					if (curcnt == (int)tmp3.size() - 1 || g0(tmp3[curcnt + 1]) != g0(tmp3[curcnt])) {
						while (!S.empty()) {
							int tmp4 = S.top();
							S.pop();
							dp[tmp4] = max(dp[tmp4], A[tmp4] + curr);
						}
					}
					curcnt++;
				}
				reverse(tmp3.begin(), tmp3.end());
				curcnt = 0, curr = LLONG_MIN;
				for (auto j : tmp3) {
					tie(aval, vval, idx) = j;
					curr = max(curr, aval + vval);
					S.push(idx);
					if (curcnt == (int)tmp3.size() - 1 || g0(tmp3[curcnt + 1]) != g0(tmp3[curcnt])) {
						while (!S.empty()) {
							int tmp4 = S.top();
							S.pop();
							dp[tmp4] = max(dp[tmp4], -A[tmp4] + curr);
						}
					}
					curcnt++;
				}
			}
			//for (int j : vec[i])
				//cout << j << ' ' << dp[j] << '\n';
		}
		cout << dp[1] << '\n';
		for (int i = 1; i <= N; i++) {
			A[i] = dep[i] = dp[i] = vis[i] = 0;
			vec[i].clear();
			adj[i].clear();
			par[i] = 0;
		}
	}
}