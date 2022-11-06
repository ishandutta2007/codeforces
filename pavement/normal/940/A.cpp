#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define pp pop
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
typedef long double ld;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, D, X[105], mem[105][105];

int dp(int l, int r) {
	if (X[r] - X[l] <= D) return 0;
	if (mem[l][r] != -1) return mem[l][r];
	return mem[l][r] = min(dp(l + 1, r), dp(l, r - 1)) + 1;
}

main() {
	memset(mem, -1, sizeof mem);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> D;
	for (int i = 1; i <= N; i++) cin >> X[i];
	sort(X + 1, X + 1 + N);
	cout << dp(1, N) << '\n';
}