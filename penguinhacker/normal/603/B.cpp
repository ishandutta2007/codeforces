#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int binPow(ll b, int p, int M) {
	ll res=1;
	while(p) {
		if (p&1)
			res=res*b%M;
		b=b*b%M;
		p>>=1;
	}
	return res;
}

const int MOD=1e9+7, mxN=1e6;
ll p, k, ans=1;
bool vis[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> p >> k;
	if (k==0) {
		cout << binPow(p, p-1, MOD) << '\n';
		return 0;
	}
	for (int i=0; i<p; ++i) {
		if (vis[i]) continue;
		int cnt=0;
		ll u=i;
		while(!vis[u]) {
			vis[u]=1;
			++cnt;
			u=u*k%p;
		}
		//cout << cnt << '\n';
		if (binPow(k, cnt, p)==1)
			ans=ans*p%MOD;
	}
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/