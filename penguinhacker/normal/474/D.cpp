#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

const int MOD = 1e9+7;

int q, k, dp[100001], pref[100001]; //dp on how many flowers eaten

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	memset(dp, 0, sizeof(dp));
	cin >> q >> k;
	for (int i=0; i<k; ++i)
		dp[i] = 1;
	for (int i=k; i<=100000; ++i)
		dp[i] = (dp[i-1]+dp[i-k])%MOD;
	pref[0] = 0;
	for (int i=1; i<=100000; ++i)
		pref[i] = (pref[i-1]+dp[i])%MOD;

	while(q--) {
		int a, b;
		cin >> a >> b;
		cout << (pref[b]-pref[a-1]+MOD)%MOD << '\n';
	}
	return 0;
}