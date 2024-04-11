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

int TC, N, K, A[100005], T[100005];
bool seen[100005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> TC;
	while (TC--) {
		cin >> N >> K;
		for (int i = 0; i <= N + 5; i++) seen[i] = 0;
		for (int i = 1; i <= N; i++) {
			cin >> A[i];
			T[i] = A[i];
		}
		sort(T + 1, T + 1 + N);
		int yep = 0, st = -1, c = 0;
		for (int i = 1; i <= N; i++) A[i] = lower_bound(T + 1, T + 1 + N, A[i]) - T;
		for (int i = 1; i <= N; i++) {
			if (i > 1 && A[i] == A[i - 1] + 1) {
				c++;
			} else {
				c = 1;
				st = A[i];
				if (i > 1) yep++;
			}
		}
		yep++;
		if (yep <= K) cout << "YES\n";
		else cout << "NO\n";
	}
}