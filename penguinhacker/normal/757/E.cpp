#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e6, M=1e9+7;
vector<int> f[mxN+1];
ll dp[mxN+1][20];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i=2; i<=mxN; ++i) {
		if (!f[i].empty())
			continue;
		for (int j=i; j<=mxN; j+=i) {
			int k=j, c=0;
			while(k%i==0)
				k/=i, ++c;
			f[j].push_back(c);
		}
	}
	dp[0][0]=1;
	//for (int i=1; i<20; ++i)
	//	dp[0][i]=dp[0][i-1]*2;
	for (int i=1; i<20; ++i)
		dp[0][i]=2;
	for (int i=1; i<=mxN; ++i) {
		int cur=0;
		for (int j=0; j<20; ++j) {
			cur=(cur+dp[i-1][j])%M;
			dp[i][j]=cur;
		}
	}
	int q;
	cin >> q;
	while(q--) {
		int n, m;
		cin >> m >> n;
		ll ans=1;
		for (int i : f[n])
			ans=ans*dp[m][i]%M;
		cout << ans << "\n";
	}
	return 0;
}