#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=5e5, M=1e9+7;
int n, a[mxN];
ll f[mxN+1], iF[mxN+1], iv[mxN+1];

ll C(int a, int b) {
	return f[a]*iF[b]%M*iF[a-b]%M;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	f[0]=f[1]=iF[0]=iF[1]=iv[1]=1;
	for (int i=2; i<=mxN; ++i) {
		f[i]=i*f[i-1]%M;
		iv[i]=M-M/i*iv[M%i]%M;
		iF[i]=iF[i-1]*iv[i]%M;
	}
	ll ans=0;
	cin >> n;
	for (int i=0; i<=n; ++i) {
		cin >> a[i];
		//for (int j=0; j<a[i]; ++j)
		//	ans=(ans+C(i+j, i))%M;
		ans=(ans+C(i+a[i], i+1))%M;
	}
	cout << ans << "\n";
	return 0;
}