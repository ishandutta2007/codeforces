#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef TEST
#define getchar_unlocked _getchar_nolock
#endif
#define int long long
#define ins insert
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define pp pop
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
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

bool hv, nhv;
int N, M, T, link[1000005], sz[1000005], tk[1005][1005], dr[] = {-1, 0, 0, 1}, dc[] = {0, -1, 1, 0};
char F[1005][1005];
bool vis[1005][1005];
queue<iii> Q;

int conv(int r, int c) {
	return (r - 1) * M + c;
}

int find(int x) {
	if (x == link[x]) return x;
	return link[x] = find(link[x]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (sz[b] > sz[a]) swap(a, b);
	sz[a] += sz[b];
	link[b] = a;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> T;
	for (int i = 1; i <= N * M; i++)
		link[i] = i, sz[i] = 1;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> F[i][j], tk[i][j] = -1;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			for (int k = 0; k < 4; k++)
				if (1 <= i + dr[k] && i + dr[k] <= N && 1 <= j + dc[k] && j + dc[k] <= M && F[i][j] == F[i + dr[k]][j + dc[k]])
					unite(conv(i, j), conv(i + dr[k], j + dc[k]));
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (sz[find(conv(i, j))] == 1) {
				hv = 1;
				for (int k = 0; k < 4; k++)
					if (1 <= i + dr[k] && i + dr[k] <= N && 1 <= j + dc[k] && j + dc[k] <= M && sz[find(conv(i + dr[k], j + dc[k]))] > 1) {
						Q.emplace(0, i, j);
						break;
					}
			} else nhv = 1;
	if (!hv) {
		for (int tc = 1, i, j, p; tc <= T; tc++) {
			cin >> i >> j >> p;
			if (p & 1) cout << char(!(F[i][j] - '0') + '0') << '\n';
			else cout << F[i][j] << '\n';
		}
		return 0;
	}
	if (!nhv) {
		for (int tc = 1, i, j, p; tc <= T; tc++) {
			cin >> i >> j >> p;
			cout << F[i][j] << '\n';
		}
		return 0;
	}
	int time, i, j;
	while (!Q.empty()) {
		auto tmp = Q.front();
		Q.pop();
		tie(time, i, j) = tmp;
		if (vis[i][j]) continue;
		vis[i][j] = 1;
		for (int k = 0; k < 4; k++)
			if (1 <= i + dr[k] && i + dr[k] <= N && 1 <= j + dc[k] && j + dc[k] <= M && sz[find(conv(i + dr[k], j + dc[k]))] > 1)
				unite(conv(i, j), conv(i + dr[k], j + dc[k]));
		for (int k = 0; k < 4; k++)
			if (1 <= i + dr[k] && i + dr[k] <= N && 1 <= j + dc[k] && j + dc[k] <= M && sz[find(conv(i + dr[k], j + dc[k]))] == 1)
				Q.emplace(time + 1, i + dr[k], j + dc[k]);
		tk[i][j] = time;
	}
	while (T--) {
		int i, j, p;
		cin >> i >> j >> p;
		if (tk[i][j] == -1) {
			if (p & 1) cout << char(!(F[i][j] - '0') + '0') << '\n';
			else cout << F[i][j] << '\n';
		} else {
			if (tk[i][j] >= p) cout << F[i][j] << '\n';
			else cout << (p - tk[i][j] & 1 ? F[i][j] : char(!(F[i][j] - '0') + '0')) << '\n';
		}
	}
}