#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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
typedef long double ld;
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int T, N, M, dr[] = {-1, 0, 0, 1}, dc[] = {0, -1, 1, 0};
char F[55][55];
bool vis[55][55];
vector<ii> need;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		need.clear();
		cin >> N >> M;
		bool good = 0;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++) {
				cin >> F[i][j];
				if (F[i][j] == 'G') good = 1;
			}
		if (!good) {
			cout << "YES\n";
			continue;
		} else {
			for (int i = 1; i <= N; i++)
				for (int j = 1; j <= M; j++)
					for (int k = 0; k < 4; k++)
						if (F[i][j] == 'B' && 1 <= i + dr[k] && i + dr[k] <= N && 1 <= j + dc[k] && j + dc[k] <= M)
							need.eb(i + dr[k], j + dc[k]);
			bool cannot = 0;
			for (auto i : need) {
				if (i.first == N && i.second == M) cannot = 1;
				else if (F[i.first][i.second] == 'G') cannot = 1;
				else if (F[i.first][i.second] == '.') F[i.first][i.second] = '#';
			}
			memset(vis, 0, sizeof vis);
			queue<ii> Q;
			Q.emplace(N, M);
			while (!Q.empty()) {
				auto tmp = Q.front();
				Q.pop();
				if (vis[tmp.first][tmp.second]) continue;
				vis[tmp.first][tmp.second] = 1;
				int i = tmp.first, j = tmp.second;
				for (int k = 0; k < 4; k++)
					if (1 <= i + dr[k] && i + dr[k] <= N && 1 <= j + dc[k] && j + dc[k] <= M && F[i + dr[k]][j + dc[k]] != '#')
						Q.emplace(i + dr[k], j + dc[k]);
			}
			for (int i = 1; i <= N; i++)
				for (int j = 1; j <= M; j++)
					cannot |= (F[i][j] == 'G' && !vis[i][j]);
			cout << (cannot ? "NO" : "YES") << '\n';
		}
	}
}