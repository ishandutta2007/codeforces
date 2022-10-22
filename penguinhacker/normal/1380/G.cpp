#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int MOD=998244353;
int n, a[300000];
ll p[300000];

int binPow(ll b, int pow=MOD-2) {
	ll res=1;
	while(pow) {
		if (pow&1) res=res*b%MOD;
		b=b*b%MOD;
		pow>>=1;	
	}
	return res;
}

ll get(int l, int r) {
	return l==0?p[r]%MOD:(p[r]-p[l-1])%MOD;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	sort(a, a+n);
	p[0]=a[0];
	for (int i=1; i<n; ++i)
		p[i]+=a[i]+p[i-1];

	const int inv=binPow(n);
	for (int i=1; i<=n; ++i) {
		int r=n-i-1, mult=1;
		ll ans=0;
		while(r>=0) {
			int l=r-i+1;
			l=max(l, 0);
			ans=(ans+mult*get(l, r))%MOD;
			r-=i;
			++mult;
		}
		ans=ans*inv%MOD;
		cout << ans << ' ';
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/