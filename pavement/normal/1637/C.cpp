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

int T, N, A[100005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		int sum = 0, cnt = 0;
		bool allones = 1;
		for (int i = 1; i <= N; i++) {
			cin >> A[i];
			if (i == 1 || i == N) continue;
			if (A[i] % 2 == 1) cnt++;
			sum += A[i];
			if (A[i] > 1) allones = 0;
		}
		int ans = LLONG_MAX;
		for (int i = 0; i <= N; i++)
			if (cnt - 2 * i >= 0) ans = min(ans, i + (cnt - 2 * i) + (sum - (cnt - 2 * i)) / 2);
		if ((N == 3 && cnt == 1) || allones) cout << "-1\n";
		else cout << ans << '\n';
	}
}