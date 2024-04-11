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

int T, N, A[2005], P[2005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		int x = 0;
		for (int i = 1; i <= N; i++) {
			cin >> A[i], x ^= A[i];
			P[i] = x;
		}
		if (x == 0) cout << "YES\n";
		else {
			bool yes = 0;
			for (int i = 2; i <= N; i++)
				for (int j = i + 1; j <= N; j++) {
					// [1, i - 1], [i, j - 1], [j, N]
					if (P[i - 1] == (P[j - 1] ^ P[i - 1]) && P[i - 1] == (P[N] ^ P[j - 1])) {
						yes = 1;
						goto hell;
					}
				}
			hell:
				if (yes) cout << "YES\n";
				else cout << "NO\n";
		}
	}
}