#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
typedef long long ll;
#define endl '\n'
using namespace std;

// Time Complexity: O(N ^ 2)

int main() {
	int n, a, b, c, dp[4001], mn = 1e9;
	cin >> n >> a >> b >> c;
	mn = min(min(a, b), c);
	for (int i = 1; i < mn; i++) dp[i] = -1e9;
	for (int i = mn; i <= n; i++) {
		dp[i] = -1e9;
		if (i == a || i == b || i == c) dp[i] = 1;
		for (int a = 1; a < i; a++)
			dp[i] = max(dp[i], dp[a] + dp[i - a]);
	}
	cout << dp[n] << endl;
	return 0;
}