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

int N, H[300005], dp[300005];
stack<int> st, st2;
vector<int> jmp[300005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> H[i];
	for (int i = N; i >= 1; i--) {
		while (!st.empty() && H[st.top()] > H[i]) st.pop();
		while (!st2.empty() && H[st2.top()] < H[i]) st2.pop();
		if (!st.empty()) jmp[i].pb(st.top());
		if (!st2.empty()) jmp[i].pb(st2.top());
		st.push(i);
		st2.push(i);
	}
	while (!st.empty()) st.pop();
	while (!st2.empty()) st2.pop();
	for (int i = 1; i <= N; i++) {
		while (!st.empty() && H[st.top()] > H[i]) st.pop();
		while (!st2.empty() && H[st2.top()] < H[i]) st2.pop();
		if (!st.empty()) jmp[st.top()].pb(i);
		if (!st2.empty()) jmp[st2.top()].pb(i);
		st.push(i);
		st2.push(i);
	}
	for (int i = N - 1; i >= 1; i--) {
		dp[i] = LLONG_MAX;
		for (int j : jmp[i]) dp[i] = min(dp[i], dp[j]);
		dp[i]++;
	}
	cout << dp[1] << '\n';
}