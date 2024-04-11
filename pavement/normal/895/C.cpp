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
typedef tree<iii, null_type, greater<iii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, A[100005], cnt[75], dp[2][600005], rev[75], pow2[100005];
map<int, int> pf[100005];
const int MOD = 1e9 + 7;

bool ip(int x) {
	if (x <= 1) return 0;
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0) return 0;
	return 1;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	pow2[0] = 1;
	for (int i = 1; i <= N; i++)
		pow2[i] = pow2[i - 1] * 2 % MOD;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		cnt[A[i]]++;
	}
	int lab = 0;
	for (int i = 1; i <= 70; i++)
		if (ip(i)) rev[i] = lab++;
	for (int i = 1; i <= 70; i++) {
		int tmp = i;
		for (int j = 2; j <= 70; j++)
			while (tmp % j == 0) {
				tmp /= j;
				pf[i][j]++;
			}
	}
	dp[0][0] = 1;
	for (int i = 1; i <= 70; i++) {
		for (int j = 0; j < (1 << 19); j++) {
			int nb = j;
			for (auto k : pf[i])
				if (k.second & 1) nb ^= (1 << rev[k.first]);
			dp[i & 1][j] = dp[i & 1 ^ 1][j] * (cnt[i] ? pow2[cnt[i] - 1] : 1) + dp[i & 1 ^ 1][nb] * (cnt[i] ? pow2[cnt[i] - 1] : 0);
			dp[i & 1][j] %= MOD;
		}
	}
	int x = dp[70 & 1][0] - 1;
	x %= MOD;
	x = (x + MOD) % MOD;
	cout << x << '\n';
}