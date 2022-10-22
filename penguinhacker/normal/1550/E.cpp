#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, k, len[mxN][17], nxt[mxN][17], dp[1<<17];
string s;

bool ok(int x) {
	for (int i=n-1; ~i; --i)
		for (int j=0; j<k; ++j)
			nxt[i][j]=len[i][j]>=x?i:i+1<n?nxt[i+1][j]:-1;
	memset(dp, 0x3f, sizeof(dp));
	dp[0]=0;
	for (int i=0; i<1<<k; ++i) {
		if (dp[i]>=n)
			continue;
		for (int j=0; j<k; ++j) {
			if (i&1<<j)
				continue;
			int pos=nxt[dp[i]][j];
			if (pos==-1)
				continue;
			dp[i|1<<j]=min(dp[i|1<<j], pos+x);
		}
	}
	return dp[(1<<k)-1]<=n;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k >> s;
	for (int i=n-1; ~i; --i)
		for (int j=0; j<k; ++j)
			if (s[i]=='a'+j||s[i]=='?')
				len[i][j]=1+(i+1<n?len[i+1][j]:0);
	int lb=0, rb=n/k;
	while(lb<rb) {
		int mid=(lb+rb+1)/2;
		if (ok(mid))
			lb=mid;
		else
			rb=mid-1;
	}
	cout << lb;
	return 0;
}