#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int MOD=1e9+7;
int n;

int bP(ll b, int pow) {
	ll res=1;
	while(pow) {
		if (pow&1) res=res*b%MOD;
		b=b*b%MOD;
		pow>>=1;
	}
	return res;
}

void test_case() {
	cin >> n;
	ll ans=1;
	for (int i=2; i<=n; ++i)
		ans=ans*i%MOD;
	ll sub=bP(2, n-1);
	ans=(ans-sub+MOD)%MOD;
	cout << ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1;
	//cin >> t;
	while(t--)
		test_case();
	return 0;
}


/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/