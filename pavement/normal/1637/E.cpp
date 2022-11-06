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

int T, N, M, ans, A[300005], rv[300005], cnt[300005], ptr[300005];
vector<int> nonzero, disc, adj[300005], vecs[300005];
vector<bool> has[300005];
ii pos[300005];

bool bad(int x, int y) {
	return binary_search(adj[x].begin(), adj[x].end(), y);
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		ans = 0;
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			cin >> A[i];
			disc.pb(A[i]);
		}
		sort(disc.begin(), disc.end());
		disc.erase(unique(disc.begin(), disc.end()), disc.end());
		for (int i = 1; i <= N; i++) {
			int tmp = A[i];
			A[i] = lower_bound(disc.begin(), disc.end(), A[i]) - disc.begin() + 1;
			rv[A[i]] = tmp;
			cnt[A[i]]++;
		}
		for (int i = 1; i <= disc.size(); i++) {
			vecs[cnt[i]].pb(i);
		}
		for (int i = 1; i <= N; i++) {
			has[i].resize(vecs[i].size());
			sort(vecs[i].begin(), vecs[i].end(), greater<int>());
			int idx = 0;
			for (int j : vecs[i])
				pos[j] = mp(i, idx++);
			if (!vecs[i].empty()) nonzero.pb(i);
		}
		for (int i = 1, x, y; i <= M; i++) {
			cin >> x >> y;
			x = lower_bound(disc.begin(), disc.end(), x) - disc.begin() + 1;
			y = lower_bound(disc.begin(), disc.end(), y) - disc.begin() + 1;
			adj[x].pb(y);
			adj[y].pb(x);
		}
		for (int i = 1; i <= disc.size(); i++) adj[i].pb(i);
		for (int i = 1; i <= disc.size(); i++) {
			for (auto u : adj[i]) {
				has[pos[u].first][pos[u].second] = 1;
				while (ptr[pos[u].first] < vecs[cnt[u]].size() && has[pos[u].first][ptr[pos[u].first]]) ptr[pos[u].first]++;
			}
			for (int j : nonzero)
				if (ptr[j] < vecs[j].size()) {
					//cout << ptr[j] << ' ' << vecs[j].size() << ' ' << rv[i] << ' ' << rv[vecs[j][ptr[j]]] << ' ' << cnt[i] << ' ' << j << '\n';
					ans = max(ans, (rv[i] + rv[vecs[j][ptr[j]]]) * (cnt[i] + j));
				}
			for (auto u : adj[i]) {
				has[pos[u].first][pos[u].second] = 0;
				ptr[pos[u].first] = 0;
			}
		}
		cout << ans << '\n';
		nonzero.clear();
		disc.clear();
		for (int i = 1; i <= N; i++) {
			rv[i] = cnt[i] = ptr[i] = 0;
			adj[i].clear();
			vecs[i].clear();
			has[i].clear();
		}
	}
}