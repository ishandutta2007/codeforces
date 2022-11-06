#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef TEST
#define getchar_unlocked _getchar_nolock
#endif
#define ins insert
#define int long long
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
typedef tuple<int, int, int, int> iiii;
typedef tree<pair<ll, int>, null_type, less<pair<ll, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int dr[] = {-1, 0}, dc[] = {0, -1};
char F[55][55];
bool can[55][55], vis[55][55];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T, N;
	cin >> T;
	while (T--) {
		queue<ii> Q;
		cin >> N;
		bool inv = 0;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++) cin >> F[i][j], can[i][j] = vis[i][j] = 0;
		for (int i = 1; i <= N; i++)
			for (int j = N; j >= 1; j--)
				if (F[j][i] == '0') break;
				else can[j][i] = 1;
		for (int i = 1; i <= N; i++)
			for (int j = N; j >= 1; j--)
				if (F[i][j] == '0') break;
				else can[i][j] = 1;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (can[i][j])
					Q.emplace(i, j);
		while (!Q.empty()) {
			auto top = Q.front();
			Q.pop();
			if (vis[top.first][top.second]) continue;
			vis[top.first][top.second] = 1;
			for (int k = 0; k < 2; k++)
				if (1 <= top.first + dr[k] && top.first + dr[k] <= N && 1 <= top.second + dc[k] && top.second + dc[k] <= N && F[top.first + dr[k]][top.second + dc[k]] == '1')
					Q.emplace(top.first + dr[k], top.second + dc[k]);
		}
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				inv |= (F[i][j] == '1' && !vis[i][j]);
		cout << (inv ? "NO" : "YES") << '\n';
	}
}