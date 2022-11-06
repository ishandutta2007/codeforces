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

int N, M, ans, a[5000005], to[5000005];
bitset<10000005> vis;

void dfs(int n) {
	vis[n] = 1;
	if (n < (1 << N)) {
		if (to[n] != -1 && !vis[to[n]]) dfs(to[n]);
		for (int j = 0; j < N; j++)
			if ((n & (1 << j)) && !vis[n ^ (1 << j)]) dfs(n ^ (1 << j));
	} else {
		int i = n - (1 << N) + 1;
		if (!vis[((1 << N) - 1) ^ a[i]]) dfs(((1 << N) - 1) ^ a[i]);
	}
}

main() {
	memset(to, -1, sizeof to);
	vis.reset();
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> a[i];
		to[a[i]] = i + (1 << N) - 1;
	}
	for (int i = 1; i <= M; i++)
		if (!vis[i + (1 << N) - 1]) dfs(i + (1 << N) - 1), ans++;
	cout << ans << '\n';
}