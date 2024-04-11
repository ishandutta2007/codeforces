#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e6, M=998244353;
int n, a[mxN], c[mxN];
ar<ll, 2> dp[mxN+1]; // stores answer for cycle of length i
ll f[mxN+1], iF[mxN+1], iv[mxN+1];

ll bp(ll b, int p=M-2) {
	ll r=1;
	for (; p; p/=2, b=b*b%M)
		if (p%2)
			r=r*b%M;
	return r;
}

void solve() {
	cin >> n;
	memset(c, 0, 4*n);
	memset(dp, 0, sizeof(dp[0])*(n+1));
	for (int i=0; i<n; ++i) {
		cin >> a[i], --a[i];
		++c[a[i]];
	}
	if (c[a[0]]==n) {
		cout << "1\n";
		return;
	}
	vector<int> b;
	for (int i=0; i<n; ++i)
		if (c[i])
			b.push_back(c[i]);
	int g=b[0];
	for (int i=1; i<b.size(); ++i)
		g=__gcd(g, b[i]);
	assert(n%g==0);
	for (int i=1; i<=g; ++i) {
		if (g%i)
			continue;
		ll cnt=f[n/i];
		for (int j : b)
			cnt=cnt*iF[j/i]%M;
		ll ev=0;
		for (int j : b) {
			j/=i;
			int m=n/i;
			ev=(ev+j*iv[m]%M*(j-1)%M*iv[m-1])%M;
		}
		ev=ev*n%M*cnt%M;
		dp[n/i]={cnt, ev};
	}
	ll ans1=0, ans2=0;
	for (int i=1; i<=n; ++i) {
		int x=__gcd(i, n);
		//x=n/x;
		if (dp[x][0]) {
			ans1=(ans1+dp[x][0])%M;
			ans2=(ans2+dp[x][1])%M;
		}
	}
	//cout << ans1 << " " << ans2 << endl;
	cout << (n-ans2*bp(ans1)%M+M)%M << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	f[0]=f[1]=iF[0]=iF[1]=iv[1]=1;
	for (int i=2; i<=mxN; ++i) {
		f[i]=f[i-1]*i%M;
		iv[i]=M-M/i*iv[M%i]%M;
		iF[i]=iF[i-1]*iv[i]%M;
	}
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}