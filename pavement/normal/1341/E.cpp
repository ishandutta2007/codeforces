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

#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif

void read(int &v) {
    v = 0;
    char ch = getchar_unlocked();
    for (; ch < '0' || ch > '9'; ch = getchar_unlocked());
    for (; '0' <= ch && ch <= '9'; ch = getchar_unlocked())
        v = (v << 3) + (v << 1) + (ch & 15);
}

int N, M, G, R, ans = LLONG_MAX, D[10005], dist[10005][1005];
deque<iii> Q;

main() {
	read(N);
	read(M);
	for (int i = 1; i <= M; i++) read(D[i]);
	sort(D + 1, D + 1 + M);
	read(G);
	read(R);
	for (int i = 1; i <= M; i++)
		for (int j = 0; j <= G; j++) dist[i][j] = LLONG_MAX;
	Q.emplace_front(0, 1, 0);
	dist[1][0] = 0;
	while (!Q.empty()) {
		auto [d, v, t] = Q.front();
		Q.pop_front();
		if (dist[v][t] != d) continue;
		if (v > 1 && t + D[v] - D[v - 1] <= G) {
			int nt = t + D[v] - D[v - 1];
			if (dist[v - 1][nt] > d) {
				dist[v - 1][nt] = d;
				Q.emplace_front(d, v - 1, nt);
			}
		}
		if (v < M && t + D[v + 1] - D[v] <= G) {
			int nt = t + D[v + 1] - D[v];
			if (dist[v + 1][nt] > d) {
				dist[v + 1][nt] = d;
				Q.emplace_front(d, v + 1, nt);
			}
		}
		if (t == G) {
			if (dist[v][0] > d + 1) {
				dist[v][0] = d + 1;
				Q.emplace_back(d + 1, v, 0);
			}
		}
	}
	for (int i = 0; i <= G; i++)
		if (dist[M][i] != LLONG_MAX) ans = min(ans, dist[M][i] * (G + R) + i);
	printf("%lld\n", ans == LLONG_MAX ? -1ll : ans);
}