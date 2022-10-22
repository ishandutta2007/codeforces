#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, dp[1<<24];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i) {
		string s;
		cin >> s;
		for (int j=1; j<8; ++j) {
			int m=0;
			for (int k=0; k<3; ++k)
				if (j&1<<k)
					m|=1<<s[k]-'a';
			dp[m]+=__builtin_popcount(j)%2?1:-1;
		}
	}
	for (int i=0; i<24; ++i)
		for (int j=1; j<1<<24; ++j)
			if (j&1<<i)
				dp[j]+=dp[j^1<<i];
	int ans=0;
	for (int i=0; i<1<<24; ++i)
		ans^=dp[i]*dp[i];
	cout << ans;
	return 0;
}