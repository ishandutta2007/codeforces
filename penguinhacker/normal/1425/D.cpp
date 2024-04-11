#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2000, M=1e9+7;
int n, m, r, x[mxN], y[mxN];
bitset<2000> adj[mxN];
ll b[mxN], f[mxN+1], iv[mxN+1], iF[mxN+1];

ll C(int a, int b) {
	if (a<b)
		return 0;
	return f[a]*iF[b]%M*iF[a-b]%M;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> r;
	for (int i=0; i<n; ++i)
		cin >> x[i] >> y[i] >> b[i];
	for (int i=0; i<n; ++i)
		for (int j=i; j<n; ++j)
			adj[i][j]=adj[j][i]=abs(x[i]-x[j])<=r&&abs(y[i]-y[j])<=r;
	f[0]=f[1]=iF[0]=iF[1]=iv[1]=1;
	for (int i=2; i<=n; ++i) {
		f[i]=f[i-1]*i%M;
		iv[i]=M-M/i*iv[M%i]%M;
		iF[i]=iF[i-1]*iv[i]%M;
	}
	ll s=accumulate(b, b+n, 0ll)%M;
	ll ans=0;
	for (int i=0; i<n; ++i) {
		int ct=n-adj[i].count();
		int eh=(C(n, m)-C(ct, m)+M)%M;
		//cout << eh << endl;
		ans=(ans+b[i]*b[i]%M*eh)%M;
		ans=(ans+b[i]*(s-b[i]+M)%M*C(n, m))%M;
		ans=(ans-b[i]*(s-b[i]+M)%M*2*C(ct, m)%M+M)%M;
		for (int j=i+1; j<n; ++j)
			ans+=2*b[i]*b[j]%M*C(n-(adj[i]|adj[j]).count(), m)%M;
	}
	cout << ans%M;
	return 0;
}