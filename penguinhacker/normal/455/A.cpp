#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
const int MOD=1e9+7;

ll n, cnt[100001]={0}, dp[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0, a; i<n; ++i) {
		cin >> a;
		cnt[a]++;
	}
	
	dp[0]=0;
	dp[1]=cnt[1];
	for (int i=2; i<=100000; ++i) {
		dp[i]=max(dp[i-1], cnt[i]*i+dp[i-2]);
	}
	cout << dp[100000];
	return 0;
}