#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int MOD = 998244353;

int binPow(ll b, int p=MOD-2) {
	ll res=1;
	while(p>0) {
		if (p&1) res=res*b%MOD;
		b=b*b%MOD;
		p>>=1;
	}
	return res;
}

vector<ll> f={1}, iF={1};
ll C(int a, int b) {
	if (a<0||b<0||b>a) return 0;
	assert(a<=(int)5e6);
	while(f.size()<=a) {
		int x=f.size();
		f.push_back(f.back()*x%MOD);
		iF.push_back(iF.back()*binPow(x)%MOD);
	}
	return f[a]*iF[b]%MOD*iF[a-b]%MOD;
}


int n, k, cur = 0, ans = 0;
ar<int, 2> e[600000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		e[2 * i] = {a, 1};
		e[2 * i + 1] = {b, 2};
	}
	sort(e, e + 2 * n);
	for (int i = 0; i < 2 * n; ++i) {
		int t = e[i][1];
		if (t == 1) {
			++cur;
			ans = (ans + C(cur - 1, k - 1)) % MOD;
		}
		else if (t == 2) { //remove segment
			--cur;
		}
	}
	cout << ans;
	return 0;
}