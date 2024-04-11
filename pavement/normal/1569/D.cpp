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

int ans, T, N, M, K, X[300005], Y[300005], x[300005], y[300005];
ii t[300005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		ans = 0;
		cin >> N >> M >> K;
		for (int i = 1; i <= N; i++) cin >> X[i];
		for (int i = 1; i <= M; i++) cin >> Y[i];
		for (int i = 1; i <= K; i++) {
			cin >> x[i] >> y[i];
			t[i] = mp(x[i], y[i]);
		}
		sort(t + 1, t + 1 + K);
		int pos = 1;
		for (int i = 1; i < N; i++) {
			while (pos <= K && t[pos].first <= X[i]) pos++;
			map<int, int> tmpp;
			while (pos <= K && t[pos].first < X[i + 1]) {
				tmpp[t[pos].second]++;
				pos++;
			}
			int run = 0;
			for (auto j : tmpp) {
				ans += run * j.second;
				run += j.second;
			}
		}
		for (int i = 1; i <= K; i++) swap(t[i].first, t[i].second);
		sort(t + 1, t + 1 + K);
		pos = 1;
		for (int i = 1; i < M; i++) {
			while (pos <= K && t[pos].first <= Y[i]) pos++;
			map<int, int> tmpp;
			while (pos <= K && t[pos].first < Y[i + 1]) {
				tmpp[t[pos].second]++;
				pos++;
			}
			int run = 0;
			for (auto j : tmpp) {
				ans += run * j.second;
				run += j.second;
			}
		}
		cout << ans << '\n';
	}
}