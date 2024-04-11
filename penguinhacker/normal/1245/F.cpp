#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m;
ll dp[30][2][2]; // 0 is tight?

ll dfs(int d, bool t1, bool t2) {
	if (d==-1)
		return 1;
	if (dp[d][t1][t2]^-1)
		return dp[d][t1][t2];
	ll r=0;
	int b1=t1?1:(n>>d&1);
	int b2=t2?1:(m>>d&1);
	for (int i=0; i<=b1; ++i) {
		for (int j=0; j<=b2; ++j) {
			if (i==1&&j==1)
				continue;
			r+=dfs(d-1, t1||i<b1, t2||j<b2);
		}
	}
	//cerr << d << " " << t1 << " " << t2 << " " << r << endl;
	return dp[d][t1][t2]=r;
}

ll solve(int a, int b) {
	if (a==-1||b==-1)
		return 0;
	n=a, m=b;
	memset(dp, -1, sizeof(dp));
	return dfs(29, 0, 0);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int l, r;
		cin >> l >> r;
		//solve(r, r);
		cout << solve(r, r)-2*solve(l-1, r)+solve(l-1, l-1) << "\n";
	}
	return 0;
}