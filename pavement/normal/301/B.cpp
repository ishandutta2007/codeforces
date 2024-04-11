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

int N, D, A[105], X[105], Y[105], dist[105];
vector<ii> adj[105];
priority_queue<ii, vector<ii>, greater<ii> > pq;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> D;
	for (int i = 2; i < N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) cin >> X[i] >> Y[i];
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (i != j) adj[i].eb(j, (llabs(X[i] - X[j]) + llabs(Y[i] - Y[j])) * D - A[j]);
	pq.emplace(0, 1);
	for (int i = 2; i <= N; i++) dist[i] = LLONG_MAX;
	while (!pq.empty()) {
		auto [d, v] = pq.top();
		pq.pop();
		if (d != dist[v]) continue;
		for (auto u : adj[v])
			if (dist[u.first] > d + u.second) {
				dist[u.first] = d + u.second;
				pq.emplace(dist[u.first], u.first);
			}
	}
	cout << dist[N] << '\n';
}