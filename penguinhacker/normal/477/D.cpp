#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array

const int mxN=5000, M=1e9+7;
int n, pre[mxN+1], pwr[mxN+1], lcp[mxN+1][mxN+1];
string s;
ar<int, 2> dp[mxN][mxN], dp_all[mxN][mxN]; // { #segments, count }

int hsh(int l, int r) {
	return (pre[r+1]-(ll)pre[l]*pwr[r-l+1]%M+M)%M;
}

ar<int, 2> cmb(ar<int, 2> a, ar<int, 2> b) {
	return {min(a[0], b[0]), (a[1]+b[1])%M};
}

bool less_than(int i, int j, int len) {
	if (lcp[i][j]>=len)
		return 1;
	return s[i+lcp[i][j]]<=s[j+lcp[i][j]];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s, n=s.size();
	pwr[0]=1;
	for (int i=0; i<n; ++i) {
		pre[i+1]=(2*pre[i]+(s[i]-'0'))%M;
		pwr[i+1]=2*pwr[i]%M;
	}
	for (int i=n-1; ~i; --i)
		for (int j=n-1; j>=i; --j)
			lcp[i][j]=s[i]==s[j]?1+lcp[i+1][j+1]:0;
	dp[0][0]=dp_all[0][0]={1, 1};
	for (int i=1; i<n; ++i) {
		dp[i][0]=dp_all[i][0]={1, 1};
		for (int j=1; j<=i; ++j) {
			dp[i][j]=dp_all[i][j]={69696969, 0};
			if (s[j]=='0')
				continue;
			int dif=i-j;
			if (dif) {
				ar<int, 2> x=dp_all[j-1][max(0, (j-1)-(dif-1))];
				++x[0];
				dp[i][j]=cmb(dp[i][j], x);
			}
			if (j-1-dif>=0&&s[j-1-dif]=='1') { // compare hashes of s[j..i] and s[j-1-dif..j-1];
				if (less_than(j-1-dif, j, dif+1)) {
					ar<int, 2> x=dp[j-1][j-1-dif];
					++x[0];
					dp[i][j]=cmb(dp[i][j], x);
				}
			}
			dp_all[i][j]=dp[i][j];
		}
		for (int j=i-1; ~j; --j)
			dp_all[i][j]=cmb(dp_all[i][j], dp_all[i][j+1]);
		//for (int j=0; j<=i; ++j)
		//	cout << "[" << j << ", " << i << "] " << dp[i][j][0] << " " << dp[i][j][1] << endl;
	}
	int ans1=0, ans2=69696969;
	for (int i=0; i<n; ++i)
		if (s[i]=='1')
			ans1=(ans1+dp[n-1][i][1])%M;
	bool seen=0;
	for (int i=n-1; ~i; --i)
		if (s[i]=='1'&&dp[n-1][i][0]<6000) {
			if (n-1-i>10&&!seen) {
				ans2=(hsh(i, n-1)+dp[n-1][i][0])%M;
				break;
			}
			if (n-1-i>10)
				break;
			seen=1;
			ans2=min(ans2, hsh(i, n-1)+dp[n-1][i][0]);
		}
	cout << ans1 << "\n" << ans2;
	return 0;
}