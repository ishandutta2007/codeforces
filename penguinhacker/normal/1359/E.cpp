#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int MOD=998244353, mxN=500001;

int binPow(ll b, int p) {
	ll res=1;
	while(p) {
		if (p&1)
			res=res*b%MOD;
		b=b*b%MOD;
		p>>=1;
	}
	return res;
}

ll f[mxN], fInv[mxN];

void init() {
	f[0]=fInv[0]=1;
	for (int i=1; i<mxN; ++i)
		f[i]=f[i-1]*i%MOD;
	for (int i=1; i<mxN; ++i)
		fInv[i]=binPow(f[i], MOD-2);
}

int getC(int a, int b) {
	if (b>a)
		return 0;
	return f[a]*fInv[b]%MOD*fInv[a-b]%MOD;
}

int n, k;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	init();
	cin >> n >> k;
	ll ans=0;
	for (int i=1; i<=n; ++i) {
		int x=(n/i)-1;
		ans+=getC(x, k-1);
		//cout << x << ' ' << k-1 << ' ' << getC(x, k-1) << '\n';
	}
	cout << ans%MOD;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/