#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=5001;
int n, k, x, a[mxN];
ll ans=0, dp[mxN][mxN], r[mxN]; //range up to i

void slideWin(int j) {
	deque<ll> q;
	for (int i=0; i<k; ++i) {
		while(!q.empty()&&dp[i][j]>=dp[q.back()][j])
			q.pop_back();
		q.push_back(i);
		r[i]=dp[q[0]][j];
	}
	for (int i=k; i<n; ++i) {
		if (q[0]==i-k) q.pop_front();
		while(!q.empty()&&dp[i][j]>=dp[q.back()][j])
			q.pop_back();
		q.push_back(i);
		r[i]=dp[q[0]][j];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k >> x;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		for (int j=1; j<=x; ++j)
			dp[i][j]=-1e18;
	}
	if ((k-1)*(x+1)+x<n) {cout << -1; return 0;}

	for (int i=0; i<k; ++i)
		dp[i][1]=a[i];
	for (int j=2; j<=x; ++j) {
		slideWin(j-1);
		//for (int i=0; i<n; ++i)
		//	cout << r[i] << ' ';
		//cout << '\n';
		for (int i=0; i<n; ++i) {
			if (i&&r[i-1]==-1e18) break;
			dp[i][j]=a[i];
			if (i) dp[i][j]+=r[i-1];
		}
	}

	ll ans=0;
	for (int i=0; i<n; ++i)
		if (n-i<=k)
			ans=max(ans, dp[i][x]);
	cout << ans;
	//i-k+1 -> i-1
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/