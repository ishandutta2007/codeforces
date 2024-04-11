#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	/*vector<bool> dp(51);
	for (int i=1; i<=50; ++i) {
		for (int j=2; j<i; ++j)
			if (i%j==0&&!dp[i-j])
				dp[i]=1;
		cout << i << " " << dp[i] << "\n";
	}*/
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		if (n>1&&__builtin_popcount(n)==1)
			cout << (__builtin_ctz(n)%2==0?"Alice":"Bob") << "\n";
		else
			cout << (n%2==0?"Alice":"Bob") << "\n";
	}
	return 0;
}