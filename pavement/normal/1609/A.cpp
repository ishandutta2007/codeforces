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

int T, N, A[25];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		int cnt = 0;
		ii mx = mp(0, 0);
		for (int i = 1; i <= N; i++) {
			cin >> A[i];
			while (A[i] % 2 == 0) {
				cnt++;
				A[i] /= 2;
			}
		}
		for (int i = 1; i <= N; i++) mx = max(mx, mp(A[i], i));
		//cout << mx.first << ' ' << mx.second << ' ' << cnt << '\n';
		int p2 = 1, ans = 0;
		for (int i = 1; i <= cnt; i++) p2 *= 2;
		//cout << p2 << '\n';
		for (int i = 1; i <= N; i++) {
			if (i != mx.second) ans += A[i];
			else ans += A[i] * p2;
		}
		cout << ans << '\n';
	}
}