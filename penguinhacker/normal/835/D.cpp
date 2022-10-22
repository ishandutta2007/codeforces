#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=5000, p=51, MOD=1e9+9;
int n, dp[mxN][mxN], ans[mxN+1];
ll pp[mxN], pre[mxN], suf[mxN];
string s;

inline bool eq(int l, int r) {
	ll h1=(pre[r]-(l?pre[l-1]:0)+MOD)%MOD, h2=(suf[l]-(r==n-1?0:suf[r+1])+MOD)%MOD;
	h1=(h1*pp[n-1-r])%MOD, h2=(h2*pp[l])%MOD;
	return h1==h2;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s, n=s.size();
	pp[0]=1; for (int i=1; i<n; ++i) pp[i]=pp[i-1]*p%MOD;
	for (int i=0; i<n; ++i) pre[i]=((s[i]-'a'+1)*pp[i]+(i?pre[i-1]:0))%MOD;
	for (int i=n-1; ~i; --i) suf[i]=((s[i]-'a'+1)*pp[n-1-i]+(i==n-1?0:suf[i+1]))%MOD;
	for (int inc=0; inc<n; ++inc) for (int i=0; i+inc<n; ++i) {
		int j=i+inc;
		if (!eq(i, j)) continue;
		int x=(j-i+1)/2-1;
		dp[i][j]=1;
		if (x>=0&&dp[i][i+x]==dp[j-x][j]) dp[i][j]=dp[i][i+x]+1;
		++ans[dp[i][j]];
	}
	for (int i=n-1; i>0; --i) ans[i]+=ans[i+1];
	for (int i=1; i<=n; ++i) cout << ans[i] << ' ';
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/