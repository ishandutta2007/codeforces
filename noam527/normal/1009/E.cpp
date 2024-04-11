#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
const int md = 998244353;
using namespace std;

int n;
vector<int> a;
vector<int> dp;

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i;
	if (n == 1) return cout << a[0] << endl, 0;

	dp.resize(n);
	dp[0] = a[0];
	dp[1] = a[0] + a[1];
	for (int i = 2; i < n; i++)
		dp[i] = ((2LL * dp[i - 1] - a[i - 1] + a[i]) % md + md) % md;

	ll pw = 1;
	for (int i = n - 1; i >= 0; i--){
		dp[i] = (dp[i] * pw) % md;
		pw = 2 * pw % md;
	}

	int ans = 0;
	for (auto &i : dp)
		ans = (ans + i) % md;
	cout << ans << endl;
}