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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, sumC, dist[100005], A[100005], C[100005];
ii T[100005];
vector<ii> adj[100005];
priority_queue<ii, vector<ii>, greater<ii> > pq;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		dist[i] = 1e16;
		cin >> A[i] >> C[i];
		T[i] = mp(A[i], C[i]);
		sumC += C[i];
	}
	sort(T + 1, T + 1 + N);
	for (int i = 1; i <= N; i++) tie(A[i], C[i]) = T[i];
	for (int i = 1; i <= N; i++) {
		int lo = i, hi = N, ans = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (A[mid] - A[i] - C[i] <= 0) ans = mid, lo = mid + 1;
			else hi = mid - 1;
		}
		if (ans != -1) adj[i].eb(ans, 0);
		if (i) adj[i].eb(i - 1, 0);
		if (ans != -1 && ans != N) adj[i].eb(ans + 1, A[ans + 1] - A[i] - C[i]);
	}
	pq.emplace(0, 1);
	dist[1] = 0;
	while (!pq.empty()) {
		auto [dst, node] = pq.top();
		pq.pop();
		if (dist[node] != dst) continue;
		for (auto u : adj[node])
			if (dst + u.second < dist[u.first]) {
				dist[u.first] = dst + u.second;
				pq.emplace(dist[u.first], u.first);
			}
	}
	cout << sumC + dist[N] << '\n';
}