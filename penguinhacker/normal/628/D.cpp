#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2000, M=1e9+7;
int n, m, d, dp[mxN][mxN];
string s;

ll dfs(int dig, int mod, bool t) { // 0 is tight 1 is loose
	if (dig==n)
		return mod==0;
	if (t&&dp[dig][mod]^-1)
		return dp[dig][mod];
	ll r=0;
	int bound=t?9:s[dig]-'0';
	if (dig%2==1) { // even position so we need d
		if (d<=bound)
			r+=dfs(dig+1, (10*mod+d)%m, t||d<bound);
	} else {
		for (int i=0; i<=bound; ++i)
			if (i^d)
				r+=dfs(dig+1, (10*mod+i)%m, t||i<bound);
	}
	r%=M;
	if (t)
		dp[dig][mod]=r;
	//cout << dig << " " << mod << " " << t << " " << r << "\n";
	return r;
}

ll solve(string _s) {
	s=_s;
	return dfs(0, 0, 0);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a, b;
	cin >> m >> d >> a >> b, n=a.size();
	memset(dp, -1, sizeof(dp));
	int ans=(solve(b)-solve(a)+M)%M;
	bool ok=1;
	int c=0;
	for (int i=0; i<n; ++i) {
		int dig=a[i]-'0';
		c=(10*c+dig)%m;
		ok&=i%2?dig==d:dig!=d;
	}
	ok&=!c;
	ans=(ans+ok)%M;
	cout << ans;
	return 0;
}