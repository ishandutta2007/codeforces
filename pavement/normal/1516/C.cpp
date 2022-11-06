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

int N, s, A[105], mem[105][100005];

bool dp(int n, int x) {
	if (x == 0) return 1;
	if (x < 0) return 0;
	if (n == 0) return 0;
	if (mem[n][x] != -1) return mem[n][x];
	return mem[n][x] = (dp(n - 1, x) || dp(n - 1, x - A[n]));
}

main() {
	memset(mem, -1, sizeof mem);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i], s += A[i];
	if (s % 2 == 0 && dp(N, s / 2)) {
		int tmp = 0, pos = -1;
		for (int i = 1; i <= N; i++)
			tmp = __gcd(tmp, A[i]);
		for (int i = 1; i <= N; i++) {
			A[i] /= tmp;
			if (A[i] & 1) {
				pos = i;
				break;
			}
		}
		assert(pos != -1);
		cout << "1\n" << pos << '\n';
	} else {
		cout << "0\n";
	}
}