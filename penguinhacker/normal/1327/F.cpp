#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=5e5, M=998244353;;
int n, m, k, b[mxN+1], p[mxN+1], ls[mxN];
ar<int, 3> a[mxN];
ll ans=1, dp[mxN+1], dp2[mxN+1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k >> m;
	for (int i=0; i<m; ++i)
		cin >> a[i][0] >> a[i][1] >> a[i][2], --a[i][0], --a[i][1];
	for (int i=0; i<k; ++i) {
		memset(b, 0, 4*n);
		memset(ls, -1, 4*n);
		for (int j=0; j<m; ++j) {
			if (a[j][2]&1<<i) {
				++b[a[j][0]];
				--b[a[j][1]+1];
			} else
				ls[a[j][1]]=max(ls[a[j][1]], a[j][0]);
		}
		for (int j=1; j<n; ++j)
			b[j]+=b[j-1];
		dp[0]=dp2[0]=1;
		int cur=-1;
		for (int j=0; j<n; ++j) {
			if (j)
				cur=max(cur, ls[j-1]);
			dp[j+1]=b[j]?0:(dp2[j]-(cur^-1?dp2[cur]:0)+M)%M;
			dp2[j+1]=(dp2[j]+dp[j+1])%M;
		}
		cur=max(cur, ls[n-1]);
		ans=ans*(dp2[n]-(cur^-1?dp2[cur]:0)+M)%M;
	}
	cout << ans;
	return 0;
}