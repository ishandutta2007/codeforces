#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
const int MOD=998244353;

ll n, k, fact[200001], factInv[200001];

ll binPow(ll b, ll pow) {
	ll res=1;
	while (pow) {
		if (pow&1)
			res=res*b%MOD;
		b=b*b%MOD;
		pow >>= 1;
	}
	return res;
}

void init() {
	fact[0]=1;
	factInv[0]=1;
	for (int i=1; i<=n; ++i)
		fact[i]=fact[i-1]*i%MOD;
	for (int i=1; i<=n; ++i)
		factInv[i]=binPow(fact[i], MOD-2);
}

ll getC(int a, int b) {
	ll res=fact[a];
	res=res*factInv[b]%MOD*factInv[a-b]%MOD;
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	if (k>=n) {
		cout << 0;
		return 0;
	}
	init();
	if (k==0) {
		cout << fact[n];
		return 0;
	}
	k=n-k;
	ll ans=0;
	for (int i=k; i>=1; --i) {
		int mult=1;
		if ((k-i)&1)
			mult=-1;
		int add=getC(k, i)*binPow(i,n)%MOD;
		if (mult==1) {
			ans=(ans+add)%MOD;
		}
		else {
			ans=(ans-add+MOD)%MOD;
		}
	}
	ans=ans*2*getC(n, k)%MOD;
	cout << ans;
	return 0;
}