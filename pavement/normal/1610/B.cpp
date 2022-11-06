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

int T, N, A[200005];

bool check(int x) {
	vector<int> y;
	for (int i = 1; i <= N; i++) if (A[i] != x) y.pb(A[i]);
	for (int i = 0; i < y.size(); i++)
		if (y[i] != y[y.size() - i - 1]) return 0;
	return 1;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		int try1 = -1, try2 = -1;
		for (int i = 1; i <= N; i++) cin >> A[i];
		for (int i = 1; i <= (N + 1) / 2; i++)
			if (A[i] != A[N - i + 1]) {
				try1 = A[i];
				try2 = A[N - i + 1];
				break;
			}
		if (try1 == -1) cout << "YES\n";
		else if (check(try1) || check(try2)) cout << "YES\n";
		else cout << "NO\n";
	}
}