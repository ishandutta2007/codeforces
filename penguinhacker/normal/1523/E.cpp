#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5, M=1e9+7;
ll f[mxN+1], iF[mxN+1], iv[mxN+1];

ll C(int a, int b) {
	if (b<0||b>a)
		return 0;
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
	for (int i=2; i<=mxN; ++i) {
		f[i]=f[i-1]*i%M;
		iv[i]=M-M/i*iv[M%i]%M;
		iF[i]=iF[i-1]*iv[i]%M;
	}
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		ll ans=1;
		for (int i=1; i<=n; ++i) {
			int n2=n-(i-1)*(k-1);
			if (n2<i)
				break;
			ans=(ans+C(n2, i)*bp(C(n, i)))%M;
		}
		cout << ans << "\n";
	}
	return 0;
}