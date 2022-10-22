#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int M=998244353;
int n, x[100], y[100];
bool vis[100];
vector<int> closest[100];
ll f[101], iF[101], iv[101];

int dist(int i, int j) {
	return abs(x[i]-x[j])+abs(y[i]-y[j]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> x[i] >> y[i];
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j)
			if (j!=i) {
				if (closest[i].empty()||dist(i, j)<dist(i, closest[i][0]))
					closest[i]={j};
				else if (closest[i].size()&&dist(i, j)==dist(i, closest[i][0]))
					closest[i].push_back(j);
			}
		closest[i].push_back(i);
		sort(closest[i].begin(), closest[i].end());
	}
	vector<int> cs; // component sizes
	for (int i=0; i<n; ++i) {
		if (vis[i])
			continue;
		bool ok=1;
		for (int j : closest[i])
			if (closest[i]!=closest[j]) {
				ok=0;
				break;
			}
		if (!ok) {
			vis[i]=1;
			cs.push_back(1);
		} else {
			for (int j : closest[i])
				vis[j]=1;
			cs.push_back(closest[i].size());
		}
	}
	//for (int i : cs)
	//	cout << i << endl;
	vector<vector<ll>> dp(cs.size(), vector<ll>(n+1)); // # components
	dp[0][1]=1;
	if (cs[0]>1)
		dp[0][cs[0]]=1;
	for (int i=1; i<cs.size(); ++i) {
		for (int j=0; j<n; ++j)
			dp[i][j+1]=(dp[i][j+1]+dp[i-1][j])%M;
		if (cs[i]>1)
			for (int j=n; j>cs[i]; --j)
				dp[i][j]=(dp[i][j]+dp[i-1][j-cs[i]])%M;
	}
	f[0]=f[1]=iF[0]=iF[1]=iv[1]=1;
	for (int i=2; i<=n; ++i) {
		f[i]=f[i-1]*i%M;
		iv[i]=M-M/i*iv[M%i]%M;
		iF[i]=iF[i-1]*iv[i]%M;
	}
	ll ans=0;
	for (int i=1; i<=n; ++i)
		ans=(ans+dp.back()[i]*f[n]%M*iF[n-i])%M;
	cout << ans;
	return 0;
}