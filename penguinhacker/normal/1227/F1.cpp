#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5, M=998244353;
int n, k, a[mxN], n2;
ll ans, mul=1, f[mxN+1], iF[mxN+1], iv[mxN+1], p2[mxN+1];

ll C(int a, int b) {
	return f[a]*iF[b]%M*iF[a-b]%M;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k, n2=n;
	if (k==1) {
		cout << 0;
		return 0;
	}
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=0; i<n; ++i)
		if (a[i]==a[(i+1)%n])
			--n2, mul=mul*k%M;
	f[0]=f[1]=iF[0]=iF[1]=iv[1]=p2[0]=1;
	for (int i=2; i<=n2; ++i) {
		f[i]=f[i-1]*i%M;
		iv[i]=M-M/i*iv[M%i]%M;
		iF[i]=iF[i-1]*iv[i]%M;
	}
	for (int i=1; i<=n2; ++i)
		p2[i]=p2[i-1]*2%M;
	ll k2=1;
	for (int i=0; i<n2; ++i) { // number of 0s
		ans=(ans+k2*C(n2, i)%M*(p2[n2-i-1]-((n2-i)%2==0?C(n2-i, (n2-i)/2)*(M+1)/2%M:0)+M))%M;
		k2=k2*(k-2)%M;
	}
	cout << ans*mul%M;
	return 0;
}