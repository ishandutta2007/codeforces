#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxK=1e6, M=1e9+7;
int n, m, k;
ll ans, f[mxK+1], iv[mxK+1], iF[mxK+1];

ll bp(ll b, int p) {
	ll r=1;
	for (; p; p/=2, b=b*b%M)
		if (p%2)
			r=r*b%M;
	return r;
}

ll C(int a, int b) {
	assert(0<=b&&b<=a&&a<=mxK);
	return f[a]*iF[b]%M*iF[a-b]%M;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	if (m==1) {
		cout << bp(k, n);
		return 0;
	}
	f[0]=f[1]=iF[0]=iF[1]=iv[1]=1;
	for (int i=2; i<=mxK; ++i) {
		f[i]=f[i-1]*i%M;
		iv[i]=M-M/i*iv[M%i]%M;
		iF[i]=iF[i-1]*iv[i]%M;
	}
	for (int i=1; i<=min(n, k); ++i) {
		ll cur=0;
		for (int j=0; j<i; ++j) {
			int s=j%2?-1:1;
			cur=(cur+C(i, j)*bp(i-j, n)%M*s+M)%M;
		}
		cur=cur*cur%M;
		//cout << cur << "\n";
		for (int j=0; j<=i; ++j) { // shared
			if (2*i-j>k)
				continue;
			ans=(ans+cur*bp(j, n*m-2*n)%M*C(k, i)%M*C(i, j)%M*C(k-i, i-j))%M;
		}
	}
	cout << ans;
	return 0;
}