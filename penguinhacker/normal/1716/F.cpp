#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxK=2000, M=998244353;
ll f[mxK+1], iF[mxK+1], iv[mxK+1], dp[mxK+1][mxK+1];

ll C(int a, int b) {
	return f[a]*iF[b]%M*iF[a-b]%M;
}

ll bp(ll b, int p=M-2) {
	ll r=1;
	for (; p; p/=2, b=b*b%M)
		if (p%2)
			r=r*b%M;
	return r;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	f[0]=f[1]=iF[0]=iF[1]=iv[1]=1;
	for (int i=2; i<=mxK; ++i) {
		f[i]=f[i-1]*i%M;
		iv[i]=M-M/i*iv[M%i]%M;
		iF[i]=iF[i-1]*iv[i]%M;
	}
	dp[0][0]=1;
	for (int i=1; i<=mxK; ++i)
		for (int j=1; j<=i; ++j)
			dp[i][j]=(dp[i-1][j]*j+dp[i-1][j-1]*j)%M;
	int t;
	cin >> t;
	while(t--) {
		int n, m, k;
		cin >> n >> m >> k;
		int m2=(m+1)/2, im=bp(m);
		ll ans=0, cur=bp(m, n);
		for (int i=1; i<=min(n, k); ++i) {
			cur=cur*(n-i+1)%M*iv[i]%M*m2%M*im%M;
			ans=(ans+cur*dp[k][i])%M;
		}
		cout << ans << "\n";
	}
	return 0;
}