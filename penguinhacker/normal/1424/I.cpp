#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
const int MOD = 1e9 + 7;

/*#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, 
    rb_tree_tag, tree_order_statistics_node_update>;

const int MOD = 1e9 + 7;
//unordered_map<ll, int> dp;
gp_hash_table<ll, int> dp;

int solve(ll n) {
	if (dp.find(n) != dp.end()) {
		return dp[n];
	}
	ll cur = 0;
	ll x = n >> 1;
	for (int i = 0; i < 4; ++i) {
		if (x >= i) {
			cur += solve(x - i);
		}
	}
	cur %= MOD;
	dp[n] = cur;
	return cur;
}*/

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	//dp[0] = 1;
	while(t--) {
		ll n;
		cin >> n;
		//n >>= 1;
		ll x = (n / 4 + 1) % MOD;
		ll ans = (n % 4 < 2 ? x * x : x * (x + 1)) % MOD;
		cout << ans << "\n";
	}
	return 0;
}