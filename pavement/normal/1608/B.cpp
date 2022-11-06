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

int T, N, a, b, OA, OB, A[100005], out[100005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> a >> b;
		if (a + b > N - 2) {
			cout << "-1\n";
			continue;
		}
		if (a == 0 && b == 0) {
			for (int i = 1; i <= N; i++) cout << i << ' ';
			cout << '\n';
			continue;
		}
		OA = a;
		OB = b;
		int lo = 1, hi = 1;
		A[1] = 1;
		for (int i = 2; i <= N; i++) {
			if (i & 1) A[i] = --lo, b--;
			else A[i] = ++hi, a--;
			if (a == 0 && b == 0 && i != N) {
				int mn = LLONG_MAX;
				for (int j = 1; j <= i; j++) {
					out[j] = A[j];
					mn = min(mn, out[j]);
				}
				for (int j = i + 1; j <= N; j++) {
					if (i & 1 ^ 1) out[j] = --lo;
					else out[j] = ++hi;
					mn = min(mn, out[j]);
				}
				for (int j = 1; j <= N; j++) cout << out[j] + 1 - mn << ' ';
				cout << '\n';
				goto done;
			}
		}
		a = OA;
		b = OB;
		lo = 1, hi = 1;
		A[1] = 1;
		for (int i = 2; i <= N; i++) {
			if (i & 1 ^ 1) A[i] = --lo, b--;
			else A[i] = ++hi, a--;
			if (a == 0 && b == 0 && i != N) {
				int mn = LLONG_MAX;
				for (int j = 1; j <= i; j++) {
					out[j] = A[j];
					mn = min(mn, out[j]);
				}
				for (int j = i + 1; j <= N; j++) {
					if (i & 1) out[j] = --lo;
					else out[j] = ++hi;
					mn = min(mn, out[j]);
				}
				for (int j = 1; j <= N; j++) cout << out[j] + 1 - mn << ' ';
				cout << '\n';
				goto done;
			}
		}
		cout << "-1\n";
		done:;
	}
}