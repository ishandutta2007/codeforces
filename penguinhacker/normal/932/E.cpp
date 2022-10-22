#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxK=5000, M=1e9+7;
int n, k;
ll f[mxK+1], iF[mxK+1], iv[mxK+1], p[mxK+1];

ll C(int a, int b) {
	return f[a]*iF[b]%M*iF[a-b]%M;
}

ll bp(ll b, int p) {
	ll r=1;
	for (; p; p/=2, b=b*b%M)
		if (p%2)
			r=r*b%M;
	return r;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	f[0]=f[1]=iF[0]=iF[1]=iv[1]=p[1]=1;
	for (int i=2; i<=k; ++i) {
		f[i]=f[i-1]*i%M;
		iv[i]=M-M/i*iv[M%i]%M;
		iF[i]=iF[i-1]*iv[i]%M;
		p[i]=bp(i, k);
	}
	ll ans=0, na=1;
	for (int i=1; i<=min(n, k); ++i) {
		ll cur=0;
		for (int j=0; j<i; ++j) {
			ll x=p[i-j]*C(i, j)%M;
			cur=(cur+(j%2?-x:x)+M)%M;
		}
		na=na*(n-i+1)%M*iv[i]%M;
		ans=(ans+na*bp(2, n-i)%M*cur)%M;
	}
	cout << ans;
	return 0;
}