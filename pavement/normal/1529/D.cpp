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

int N, vec[2000005];
const int MOD = 998244353;

int g(int x) {
	return vec[2 * x];
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 2; i <= 2 * N; i += 2)
		for (int j = i + i; j <= 2 * N; j += i)
			vec[j]++;
	if (N == 1) {
		cout << "1\n";
		return 0;
	}
	int sf = 2;
	for (int i = 2; i < N; i++)
		sf += sf + g(i), sf %= MOD;
	cout << (sf + g(N)) % MOD << '\n';
}