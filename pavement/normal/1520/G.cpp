#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif
//#define int long long
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

int N, M, dr[] = {-1, 0, 0, 1}, dc[] = {0, -1, 1, 0};
ll W, A[2005][2005], dist[5000005];
vector<ii> to;
priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > pq;

inline int conv(int r, int c) {
	return (r - 1) * M + c;
}

ii rev(int x) {
	int r = (x - 1) / M + 1, c = (x - 1) % M + 1;
	return mp(r, c);
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> W;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> A[i][j];
			if (A[i][j] > 0) to.eb(i, j);
		}
	}
	fill(dist, dist + 5000005, 1e18);
	dist[1] = 0;
	pq.emplace(0, 1);
	while (!pq.empty()) {
		auto [dst, curr] = pq.top();
		pq.pop();
		if (dst != dist[curr]) continue;
		if (curr == 0) {
			for (auto i : to)
				if (dst + A[i.first][i.second] < dist[conv(i.first, i.second)]) {
					dist[conv(i.first, i.second)] = dst + A[i.first][i.second];
					pq.emplace(dist[conv(i.first, i.second)], conv(i.first, i.second));
				}
			continue;
		}
		auto [i, j] = rev(curr);
		if (A[i][j] > 0 && dst + A[i][j] < dist[0]) {
			dist[0] = dst + A[i][j];
			pq.emplace(dist[0], 0);
		}
		for (int k = 0; k < 4; k++) {
			int ni = i + dr[k], nj = j + dc[k];
			if (1 <= ni && ni <= N && 1 <= nj && nj <= M && A[ni][nj] >= 0 && dst + W < dist[conv(ni, nj)]) {
				dist[conv(ni, nj)] = dst + W;
				pq.emplace(dist[conv(ni, nj)], conv(ni, nj));
			}
		}
	}
	cout << (dist[conv(N, M)] == 1e18 ? -1 : dist[conv(N, M)]) << '\n';
}