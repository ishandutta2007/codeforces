#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5, M=998244353;
int n;
ll ans[mxN+1];

ll bp(ll b, int p=M-2) {
	ll r=1;
	for (; p; p>>=1, b=b*b%M)
		if (p&1)
			r=r*b%M;
	return r;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	ll p=1, sub=0, sum=0;
	for (int i=n; i; --i) {
		p=p*10%M;
		ll cur=(n-i+1)*p%M;
		sub=(sub+sum)%M;
		ans[i]=cur=(cur-sub+M)%M;
		sub=(sub+cur)%M;
		sum=(sum+cur)%M;
	}
	for (int i=1; i<=n; ++i)
		cout << ans[i] << " ";
	return 0;
}