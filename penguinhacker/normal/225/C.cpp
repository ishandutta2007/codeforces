#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
const int MOD=1e9+7;

int n, m, x, y;
int a[1000]={0}, sum[1000], dp[1000][2]; //dp[ends at column i][white or black]
string s[1000];

int getSum(int l, int r) { // (inclusive [l, r])
	if (l==0)
		return sum[r];
	else
		return sum[r]-sum[l-1];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> x >> y;
	for (int i=0; i<n; ++i)
		cin >> s[i];
	for (int i=0; i<m; ++i)
		for (int j=0; j<n; ++j)
			if (s[j][i]=='#')
				a[i]++;
	sum[0]=a[0];
	for (int i=1; i<m; ++i)
		sum[i]=sum[i-1]+a[i];

	memset(dp, 0x3f, sizeof(dp));
	for (int i=0; i<m; ++i) {
		for (int j=x; j<=y; ++j) {
			if (i-j<-1)
				continue;
			if (i-j==-1) {
				dp[i][0]=min(dp[i][0], getSum(0, i));
				dp[i][1]=min(dp[i][1], j*n-getSum(0, i));
			}
			else {
				dp[i][0]=min(dp[i][0], getSum(i-j+1, i)+dp[i-j][1]);
				dp[i][1]=min(dp[i][1], j*n-getSum(i-j+1, i)+dp[i-j][0]);
			}
		}
	}
	
	int ans=min(dp[m-1][0], dp[m-1][1]);
	cout << ans;
	return 0;
}