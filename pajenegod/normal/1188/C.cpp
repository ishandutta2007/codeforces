// Not my code https://codeforces.com/contest/1188/submission/107017058
 
#pragma GCC optimize ("O2")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mem(x, y) memset(& x, y, sizeof(x))
#define all(x) begin(x), end(x)
#define SZ(x) (int)(x).size()
using namespace std;
 
const int n0=1003,m=1e5,mod=998244353;
int n,k,a[n0],dp[2][n0],b[n0];
 
int calc(int gap) {
	for(int i=1; i<=n; i++)
		b[i]=upper_bound(a+1,a+n+1,a[i]-gap)-a-1;
	mem(dp,0);
	for(int j=0; j<=n; j++)
		dp[0][j]=1;
	for(int i=1; i<=k; i++) {
		dp[i&1][0]=0;
		for(int j=1; j<=n; j++) {
			int &x=dp[i&1][j];
			x=dp[i&1][j-1]+dp[(i-1)&1][b[j]];
			x=(x>=mod)?(x-mod):x;
		}
	}
	return dp[k&1][n];
}
 
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int karan=100,great=30;
	while(karan--) great=great%4+3;
	if(great==7) return 0;
	cin >> n >> k;
	for(int i=1; i<=n; i++) cin >> a[i];
	sort(a+1,a+n+1);
	int res=0;
	for(int gap=1; gap<=m/(k-1); gap++) {
		res+=calc(gap);
		if(res>=mod) res-=mod;
	}
	cout << res;
}