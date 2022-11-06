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

const int MOD = 1e9 + 7;
int N, P, ans, A[200005], fib[200005], pfib[200005], msb[200005];
bool useless[200005];

bool valid(int k) {
	int cnt = 0;
	for (int i = 0; i < 30; i++)
		if (k & (1 << i)) {
			if (cnt & 1) return 0;
			cnt = 0;
		} else cnt++;
	return 1;
}

main() {
	memset(msb, -1, sizeof msb);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> P;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 29; i >= 0; i--) {
		set<int> has;
		for (int j = 1; j <= N; j++)
			if (msb[j] == -1 && A[j] & (1 << i))
				has.insert(A[j]);
		for (int j = 1; j <= N; j++)
			if (msb[j] != -1) {
				int tmp = 0;
				for (int k = 0; k < msb[j] - i; k++) tmp |= (A[j] & (1 << k));
				tmp |= (1 << (msb[j] - i));
				if (has.count(A[j] >> (msb[j] - i)) && valid(tmp)) useless[j] = 1;
			} else if (A[j] & (1 << i)) msb[j] = i;
	}
	fib[0] = 1;
	pfib[0] = 1;
	for (int i = 1; i <= P; i++) {
		fib[i] = (fib[i - 1] + (i >= 2 ? fib[i - 2] : 0ll)) % MOD;
		pfib[i] = (pfib[i - 1] + fib[i]) % MOD;
	}
	for (int i = 1; i <= N; i++)
		if (!useless[i])
			ans = (ans + (P - msb[i] - 1 >= 0 ? pfib[P - msb[i] - 1] : 0ll)) % MOD;
	cout << ans << '\n';
}