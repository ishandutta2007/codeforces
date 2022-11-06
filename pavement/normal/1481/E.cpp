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
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define g0(a) get<0>(a)
#define g1(a) get<1>(a)
#define g2(a) get<2>(a)
#define g3(a) get<3>(a)
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef double db;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, ans, A[500005], L[500005], R[500005], cnt[500005], dp[500005];
vector<ii> rng[500005], seg[500005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		if (!L[A[i]]) L[A[i]] = i;
		R[A[i]] = i;
		cnt[A[i]]++;
		if (A[i - 1] != A[i]) {
			seg[A[i]].eb(i, 1);
		} else seg[A[i]].back().second++;
	}
	for (int i = 1; i <= N; i++)
		if (L[i])
			rng[R[i]].eb(L[i], cnt[i]);
	for (int i = 1; i <= N; i++) {
		dp[i] = dp[i - 1];
		for (auto j : rng[i])
			dp[i] = max(dp[i], dp[j.first - 1] + j.second);
	}
	ans = N - dp[N];
	for (int i = 1; i <= N; i++) {
		int cum = 0;
		for (int j = (int)seg[i].size() - 1; j >= 0; j--) {
			cum += seg[i][j].second;
			ans = min(ans, N - dp[seg[i][j].first - 1] - cum);
		}
	}
	cout << ans << '\n';
}