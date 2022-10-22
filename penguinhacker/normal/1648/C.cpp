#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5, M=998244353;
int n, m, a[mxN], b[mxN], cnt[mxN];
ll f[mxN+1], iF[mxN+1], iv[mxN+1], ft[mxN+1];

void upd(int i, ll x) {
	for (++i; i<=mxN; i+=i&-i)
		ft[i]=(ft[i]+x)%M;
}

ll qry(int i) {
	ll r=0;
	for (++i; i; i-=i&-i)
		r=(r+ft[i])%M;
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
	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> a[i], --a[i];
		++cnt[a[i]];
	}
	for (int i=0; i<m; ++i)
		cin >> b[i], --b[i];
	ll ans=0, cur=f[n];
	for (int i=0; i<mxN; ++i) {
		cur=cur*iF[cnt[i]]%M;
		if (cnt[i])
			upd(i, cnt[i]);
	}
	//cout << cur << "\n";
	bool ok=1;
	for (int i=0; i<min(n-1, m); ++i) {
		cur=cur*iv[n-i]%M;
		ans=(ans+cur*qry(b[i]-1))%M;
		if (!cnt[b[i]]) {
			ok=0;
			break;
		}
		//cout << cur << " " << ans << "\n";
		cur=cur*cnt[b[i]]%M;
		upd(b[i], (M-cnt[b[i]])%M);
		--cnt[b[i]];
		if (cnt[b[i]])
			upd(b[i], cnt[b[i]]);
	}
	if (ok&&n<m&&cnt[b[n-1]])
		ans=(ans+1)%M;
	cout << ans;
	return 0;
}