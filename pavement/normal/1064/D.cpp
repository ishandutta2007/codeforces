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

int ans, N, M, R, C, X, Y, dist[2005][2005], dr[] = {0, -1, 0, 1}, dc[] = {-1, 0, 1, 0};
char F[2005][2005];
deque<iii> Q;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> R >> C >> X >> Y;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			cin >> F[i][j];
			dist[i][j] = 1e9;
		}
	Q.emplace_front(0, R, C);
	dist[R][C] = 0;
	while (!Q.empty()) {
		auto [d, r, c] = Q.front();
		Q.pop_front();
		if (dist[r][c] != d) continue;
		for (int k = 0; k < 4; k++) {
			int nr = r + dr[k], nc = c + dc[k];
			if (1 <= nr && nr <= N && 1 <= nc && nc <= M && F[nr][nc] == '.' && dist[nr][nc] > d + !k) {
				dist[nr][nc] = d + !k;
				if (!k) Q.emplace_back(d + 1, nr, nc);
				else Q.emplace_front(d, nr, nc);
			}
		}
	}
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (F[i][j] == '.' && dist[i][j] <= X && dist[i][j] + j - C <= Y) ans++;
	cout << ans << '\n';
}