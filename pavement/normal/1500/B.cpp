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

int N, M, K, g, lc, A[500005], B[500005], x[1000005];
ii occ[1000005];

int ex_euclid(int a, int b, int &x, int &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int x1, y1, d = ex_euclid(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}

void bezout(int a, int b, int c, int &x0, int &y0) {
	int g = ex_euclid(llabs(a), llabs(b), x0, y0);
	x0 *= c / g;
	y0 *= c / g;
	if (a < 0) x0 = -x0;
	if (b < 0) y0 = -y0;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> K;
	g = __gcd(N, M);
	lc = N * M / g;
	for (int i = 1; i <= 2 * max(N, M); i++)
		occ[i] = mp(-1ll, -1ll);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		occ[A[i]].first = i;
	}
	for (int i = 0; i < M; i++) {
		cin >> B[i];
		occ[B[i]].second = i;
	}
	for (int i = 1, n1, n2; i <= 2 * max(N, M); i++) {
		if (occ[i].first != -1 && occ[i].second != -1 && occ[i].first % g == occ[i].second % g) {
			bezout(N, M, g, n1, n2);
			x[i] = (occ[i].first * n2 * M + occ[i].second * n1 * N) / g;
			x[i] = (x[i] % lc + lc) % lc + 1;
		}
	}
	int lo = 1, hi = 1e18, ans = 0;
	while (lo <= hi) {
		int mid = (lo + hi) / 2, tot = 0;
		for (int i = 1; i <= 2 * max(N, M); i++)
			if (x[i]) tot += (mid + lc - x[i]) / lc;
		tot = mid - tot;
		if (tot < K) lo = mid + 1;
		else ans = mid, hi = mid - 1;
	}
	cout << ans << '\n';
}