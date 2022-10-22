#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e6, M=1e9+7;
int n, k, prv[26];
string t;
ll dp[2*mxN+1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k >> t;
	memset(prv, -1, 4*k);
	dp[0]=1;
	for (int i=0; i<t.size(); ++i) {
		int x=t[i]-'a';
		dp[i+1]=(dp[i]+(dp[i]-(prv[x]^-1?dp[prv[x]]:0)+M)%M)%M;
		prv[x]=i;
	}
	for (int i=t.size(); i<t.size()+n; ++i) {
		int x=0;
		for (int j=1; j<k; ++j)
			if (prv[j]<prv[x])
				x=j;
		dp[i+1]=(dp[i]+(dp[i]-(prv[x]^-1?dp[prv[x]]:0)+M)%M)%M;
		prv[x]=i;
	}
	cout << dp[t.size()+n];
	return 0;
}