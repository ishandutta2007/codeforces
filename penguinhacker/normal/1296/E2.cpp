#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN = 200000;
int n, dp[200000], mx[26];
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	fill(dp, dp + n, 1);
	for (int i = 0; i < n; ++i) {
		int c = s[i] - 'a';
		for (int j = c + 1; j < 26; ++j) {
			dp[i] = max(dp[i], mx[j] + 1);
		}
		mx[c] = max(mx[c], dp[i]);
	}
	cout << *max_element(mx, mx + 26) << "\n";
	for (int i = 0; i < n; ++i) {
		if (i > 0) {
			cout << " ";
		}
		cout << dp[i];
	}
	return 0;
}