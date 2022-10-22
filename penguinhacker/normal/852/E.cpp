#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int MOD=1e9+7;
int n, cnt[100000], p[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	p[0]=1;
	for (int i=1; i<n; ++i)
		p[i]=(p[i-1]<<1)%MOD;
	for (int i=1; i<n; ++i) {
		int a, b; cin >> a >> b, --a, --b;
		++cnt[a], ++cnt[b];
	}
	int num=n; //number of non-leaves
	for (int i=0; i<n; ++i)
		if (cnt[i]==1)
			--num;
	ll ans=(1ll*num*(p[num])+1ll*(n-num)*p[num+1])%MOD;
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/