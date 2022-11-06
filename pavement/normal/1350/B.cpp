#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef TEST
#define getchar_unlocked _getchar_nolock
#endif
#define int long long
#define ins insert
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define pp pop
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define g0(a) get<0>(a)
#define g1(a) get<1>(a)
#define g2(a) get<2>(a)
#define g3(a) get<3>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef double db;
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int S[100005], dp[100005];
vector<int> fac[100005];

vector<int> getFactors(int n) {
	vector<int> res;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			if (n / i == i) res.pb(i);
			else res.pb(i), res.pb(n / i);
		}
	}
	return res;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T, N;
	cin >> T;
	for (int i = 1; i <= 1e5; i++)
		fac[i] = getFactors(i);
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++) cin >> S[i];
		for (int i = 1; i <= N; i++) {
			dp[i] = 1;
			for (int j : fac[i])
				if (i != j && S[i] > S[j]) dp[i] = max(dp[i], dp[j] + 1);
		}
		cout << *max_element(dp + 1, dp + 1 + N) << '\n';
	}
}