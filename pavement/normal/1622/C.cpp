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

int T, N, K, op, S, ans, A[200005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		op = S = 0;
		ans = LLONG_MAX;
		cin >> N >> K;
		for (int i = 1; i <= N; i++) cin >> A[i], S += A[i];
		sort(A + 1, A + 1 + N);
		if (S <= K) ans = 0;
		for (int i = N + 1, tmp = 0; i >= 2; i--) {
			if (i <= N) tmp += A[i];
			// choose mid such that
			// (N - i + 1) * mid <= K - S + tmp + A[1] - mid
			// // (N - i + 2) * mid <= K - S + tmp + A[1]
			int mid = (int)floor((ld)(K - S + tmp + A[1]) / (ld)(N - i + 2));
			ans = min(ans, max(0ll, A[1] - mid) + N - i + 1);
			//cout << K - S + tmp + A[1] << ' ' << (N - i + 2) << ' ' << i << ' ' << mid << ' ' << max(0ll, A[1] - mid) + (N - i + 1) << '\n';
		}
		cout << ans << '\n';
	}
}