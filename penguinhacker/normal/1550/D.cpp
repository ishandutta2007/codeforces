#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3e5, M=1e9+7;
int n, l, r;
ll f[mxN], iv[mxN], iF[mxN];

ll C(int a, int b) {
	return f[a]*iF[b]%M*iF[a-b]%M;
}

void solve() {
	cin >> n >> l >> r;
	ll ans=0;
	int k=min(r-n, 1-l);
	ans+=k*C(n, n/2)*(1+n%2)%M;
	for (int i=k+1; ; ++i) {
		int ls=min(n, r-i), rs=min(n, n-(l+i)+1);
		if (min(ls, rs)<n/2||max(ls, rs)<(n+1)/2)
			break;
		assert(ls<n||rs<n);
		auto Ck=[&](int nl, int nr) {
			nl-=n-rs, nr-=n-ls;
			if (nl>=0&&nr>=0)
				ans=(ans+C(nl+nr, nl))%M;
		};
		Ck(n/2, (n+1)/2);
		if (n%2)
			Ck((n+1)/2, n/2);
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	f[0]=f[1]=iF[0]=iF[1]=iv[1]=1;
	for (int i=2; i<mxN; ++i) {
		f[i]=i*f[i-1]%M;
		iv[i]=M-M/i*iv[M%i]%M;
		iF[i]=iv[i]*iF[i-1]%M;
	}
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}