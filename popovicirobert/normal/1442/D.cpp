#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;


ll solve(int l, int r, int k, vector<vector<ll>>& arr, vector<ll>& dp) {
	if(l == r) {
		ll ans = 0;
		for(int i = 0; i < (int)arr[l].size(); i++) {
			ans = max(ans, arr[l][i] + dp[k - i]);
		}
		return ans;
	}

	int mid = (l + r) / 2;
	ll ans = 0;

	vector<ll> temp = dp;
	for(int i = mid + 1; i <= r; i++) {
		int sz = (int)arr[i].size() - 1;
		for(int j = k; j >= sz; j--) {
			dp[j] = max(dp[j], dp[j - sz] + arr[i][sz]);
		}
	}

	ans = max(ans, solve(l, mid, k, arr, dp));

	dp = temp;

	for(int i = l; i <= mid; i++) {
		int sz = (int)arr[i].size() - 1;
		for(int j = k; j >= sz; j--) {
			dp[j] = max(dp[j], dp[j - sz] + arr[i][sz]);
		}
	}

	ans = max(ans, solve(mid + 1, r, k, arr, dp));

	dp = temp;

	return ans;
}



int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int i, n, k;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

   	cin >> n >> k;
   	vector<vector<ll>> arr(n);
   	for(i = 0; i < n; i++) {
   		int sz;
   		cin >> sz;

		arr[i].resize(sz + 1);
   		for(int j = 1; j <= sz; j++) {
   			cin >> arr[i][j];
   			arr[i][j] += arr[i][j - 1];
   		}
   		if(sz > k) {
   			arr[i].resize(k + 1);
   		}
   	}

   	vector<ll> dp(k + 1, -1e18);
   	dp[0] = 0;
   	
   	cout << solve(0, n - 1, k, arr, dp);

    return 0;
}