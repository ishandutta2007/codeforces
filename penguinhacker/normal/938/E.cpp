#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e6, M=1e9+7;
int n, p;
map<int, int> mp;
ll ans, f[mxN+1], iv[mxN+1], iF[mxN+1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i) {
		int x;
		cin >> x, ++mp[x];
	}
	f[0]=f[1]=iv[1]=iF[0]=iF[1]=1;
	for (int i=2; i<=n; ++i) {
		f[i]=f[i-1]*i%M;
		iv[i]=M-M/i*iv[M%i]%M;
		iF[i]=iF[i-1]*iv[i]%M;
	}
	for (auto& x : mp) {
		ll a=x.first, c=x.second;
		int y=n-p-1; // number of stuff >=x
		if (y==c-1)
			continue;
		ans=(ans+a*c%M*f[y]%M*f[n]%M*iF[y+1])%M;
		p+=c;
	}
	cout << ans;
	return 0;
}