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
using db = double;
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using iiii = tuple<int, int, int, int>;
using ordered_set = tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update>;

int T, N, A[200005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++) cin >> A[i];
		if (is_sorted(A + 1, A + 1 + N)) {
			cout << "0\n";
			continue;
		}
		if (A[N - 1] > A[N]) {
			cout << "-1\n";
			continue;
		}
		int tmp = A[N - 1] - A[N];
		if (tmp <= A[N - 1]) {
			cout << N - 2 << '\n';
			for (int i = N - 2; i >= 1; i--)
				cout << i << ' ' << N - 1 << ' ' << N << '\n';
		} else {
			cout << "-1\n";
		}
	}
}