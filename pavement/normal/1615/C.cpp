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

int T, N;
char A[100005], B[100005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++) cin >> A[i], A[i] -= '0';
		for (int i = 1; i <= N; i++) cin >> B[i], B[i] -= '0';
		int odd = 0, even = 0, ans = LLONG_MAX, ft = 0, st = 0;
		for (int i = 1; i <= N; i++) {
			if (A[i] != B[i]) {
				if (A[i]) ft++;
				else st++;
				even++;
			}
		}
		if ((even & 1 ^ 1) && ft == st) ans = min(ans, even);
		ft = st = 0;
		for (int i = 1; i <= N; i++) {
			A[i] = !A[i];
			if (A[i] != B[i]) {
				if (A[i]) ft++;
				else st++;
				odd++;
			}
		}
		if ((odd & 1) && ft + 1 == st) ans = min(ans, odd);
		cout << (ans == LLONG_MAX ? -1 : ans) << '\n';
	}
}