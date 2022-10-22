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

int n, m;
int d[200000];
ll ps[200001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> d[i];
	}
	sort(d, d + n);
	for (int i = 1; i <= n; ++i) {
		ps[i] = ps[i - 1] + d[i - 1];
	}
	auto Get = [&](int l, int r) {
		return (ps[r + 1] - ps[l]) % MOD;
	};
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		int ind = lower_bound(d, d + n, b) - d;
		// from ind ---> n - 1
		int cntSmall = ind, cntBig = n - ind;
		int prob1 = 1ll * Get(0, ind - 1) * max(0, cntBig - a + 1) % MOD * binPow(cntBig + 1) % MOD;
		int prob2 = 1ll * Get(ind, n - 1) * max(0, cntBig - a) % MOD * binPow(cntBig) % MOD;
		int ans = (prob1 + prob2) % MOD;
		cout << ans << "\n";
	}
	return 0;
}