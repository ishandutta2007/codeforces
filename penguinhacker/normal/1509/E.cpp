#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const ll INF=2e18;
ll dp[100001], p[100001];

void solve(int n, ll k, int s) {
	//cerr << "dbg : " << n << " " << k << "\n";
	if (n==0) {
		cout << "\n";
		return;
	}
	if (dp[n]==k) {
		for (int i=n-1; ~i; --i)
			cout << s+i << " ";
		cout << "\n";
		return;
	}
	assert(n>1);
	if (dp[n-1]>=k) {
		cout << s << " ";
		solve(n-1, k, s+1);
		return;
	}
	int l=1, r=n-1;
	while(l<r) {
		int mid=(l+r+1)/2;
		if (p[n-1]-p[n-mid-1]<k)
			l=mid;
		else
			r=mid-1;
	}
	for (int i=l; ~i; --i)
		cout << s+i << " ";
	solve(n-l-1, k-(p[n-1]-p[n-l-1]), s+l+1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i=1; i<=100000; ++i) {
		dp[i]=min(INF, p[i-1]+1);
		p[i]=min(INF, p[i-1]+dp[i]);
	}
	//cout << dp[1] << " " << dp[2] << " " << dp[3] << " " << dp[4] << "\n";
	int t;
	cin >> t;
	while(t--) {
		int n;
		ll k;
		cin >> n >> k;
		if (k>dp[n]) {
			cout << "-1\n";
			continue;
		}
		solve(n, k, 1);
	}
	return 0;
}