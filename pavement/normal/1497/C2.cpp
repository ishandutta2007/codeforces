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

int T, N, K;

int lcm(int a, int b) {
	return a * b / __gcd(a, b);
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> K;
		while (K != 3) {
			cout << "1 ";
			K--;
			N--;
		}
		if (N & 1) {
			cout << "1 " << (N - 1) / 2 << ' ' << (N - 1) / 2 << '\n';
		} else {
			int x = N / 2 - 1;
			while (true) {
				if (lcm(N - 2 * x, x) <= N / 2) {
					cout << N - 2 * x << ' ' << x << ' ' << x << '\n';
					break;
				}
				x--;
			}
		}
	}
}