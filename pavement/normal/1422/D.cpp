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
#define db double
//typedef double db;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, M, Sx, Sy, Fx, Fy, ans, X[100005], Y[100005], idx[100005], dist[100005], OX[100005], OY[100005];
iii T[100005];
vector<ii> adj[100005];
priority_queue<ii, vector<ii>, greater<ii> > pq;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> Sx >> Sy >> Fx >> Fy;
	ans = llabs(Sx - Fx) + llabs(Sy - Fy);
	for (int i = 0; i <= M + 1; i++) dist[i] = LLONG_MAX;
	for (int i = 1; i <= M; i++) {
		cin >> X[i] >> Y[i];
		OX[i] = X[i];
		OY[i] = Y[i];
		adj[0].eb(i, min(llabs(Sx - X[i]), llabs(Sy - Y[i])));
		adj[i].eb(0, min(llabs(Sx - X[i]), llabs(Sy - Y[i])));
		T[i] = mt(X[i], Y[i], i);
	}
	sort(T + 1, T + 1 + M);
	for (int i = 1; i <= M; i++) {
		tie(X[i], Y[i], idx[i]) = T[i];
		if (i > 1) {
			adj[idx[i]].eb(idx[i - 1], X[i] - X[i - 1]);
			adj[idx[i - 1]].eb(idx[i], X[i] - X[i - 1]);
		}
		T[i] = mt(Y[i], X[i], idx[i]);
	}
	sort(T + 1, T + 1 + M);
	for (int i = 1; i <= M; i++) {
		tie(Y[i], X[i], idx[i]) = T[i];
		if (i > 1) {
			adj[idx[i]].eb(idx[i - 1], Y[i] - Y[i - 1]);
			adj[idx[i - 1]].eb(idx[i], Y[i] - Y[i - 1]);
		}
	}
	pq.emplace(0, 0);
	dist[0] = 0;
	while (!pq.empty()) {
		auto curr = pq.top();
		pq.pop();
		if (dist[curr.second] != curr.first) continue;
		for (auto u : adj[curr.second]) {
			if (dist[u.first] > curr.first + u.second) {
				dist[u.first] = curr.first + u.second;
				pq.emplace(dist[u.first], u.first);
			}
		}
	}
	for (int i = 1; i <= M; i++)
		ans = min(ans, dist[i] + llabs(Fx - OX[i]) + llabs(Fy - OY[i]));
	cout << ans << '\n';
}