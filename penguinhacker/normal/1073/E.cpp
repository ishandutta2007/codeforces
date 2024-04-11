#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int M=998244353;
int k;
ar<ll, 2> dp[19][1<<10][2]; // {sum, count}

ll solve(ll n) {
	vector<int> d;
	while(n) {
		d.push_back(n%10);
		n/=10;
	}
	reverse(d.begin(), d.end());
	memset(dp, 0, sizeof(dp));
	for (int i=0; i<1<<10; ++i)
		if (__builtin_popcount(i)<=k)
			dp[d.size()][i][0]=dp[d.size()][i][1]={0, 1};
	ll p=1;
	for (int i=(int)d.size()-1; ~i; --i) {
		for (int j=0; j<1<<10; ++j) {
			for (int k : {0, 1}) {
				int bnd=k?9:d[i];
				for (int l=0; l<=bnd; ++l) {
					int nj=j|1<<l;
					nj-=nj==1;
					ar<ll, 2> a=dp[i+1][nj][k||l<bnd];
					dp[i][j][k][0]+=a[0]+a[1]*l*p%M;
					dp[i][j][k][1]+=a[1];
				}
				dp[i][j][k][0]%=M;
				dp[i][j][k][1]%=M;
			}
		}
		p=10*p%M;
	}
	return dp[0][0][0][0];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll l, r;
	cin >> l >> r >> k;
	cout << (solve(r)-solve(l-1)+M)%M;
	return 0;
}