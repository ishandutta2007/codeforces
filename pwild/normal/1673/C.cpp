#include <bits/stdc++.h>
using namespace std;

bool is_palindrome(int n) {
	string s = to_string(n);
	string t = s;
	reverse(begin(t), end(t));
	return s == t;
}

const int N = 4e4 + 10, MOD = 1e9 + 7;

int main() {
	vector<int> dp(N);
	dp[0] = 1;
	for (int k = 1; k < N; k++) {
		if (!is_palindrome(k)) continue;
		for (int i = k; i < N; i++) {
			dp[i] = (dp[i] + dp[i-k]) % MOD;
		}
	}
	
	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;
		cout << dp[n] << '\n';
	}
}