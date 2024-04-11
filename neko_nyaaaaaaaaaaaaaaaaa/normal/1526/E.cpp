#include <bits/stdc++.h>
using namespace std;

#define int long long
const int M = 998244353;
const int MAXN = 200000;
vector<int> ft(MAXN + 2);

int modpow(int n, int k) {
	int ans = 1;
	while (k) {
		if (k % 2) ans = (ans*n) % M;
		n = (n*n) % M; k /= 2;
	}
	return ans;
}

void init() {
	ft[0] = 1;
	for (int i = 1; i <= MAXN; i++) {
		ft[i] = (ft[i-1] * i) % M;
	}
}

int nCk(int n, int k) {
	int p = ft[n];
	int q = (ft[k] * ft[n-k]) % M;
	return (p*modpow(q, M-2)) % M;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	init();
	
	int n, k; cin >> n >> k;
	vector<int> p(n+1), pos(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> p[i]; pos[p[i]] = i;
	}

	int mn = 1, lnk = 0;
	for (int i = 1; i < n; i++) {
		if (pos[p[i] + 1] > pos[p[i+1] + 1]) {
			mn++;
		} else {
			lnk++;
		}
	}

	int ans = 0;
	for (int alph = mn, i = 0; alph <= min(n, k); alph++, i++) {
		int ct1 = nCk(lnk, i);
		int ct2 = nCk(k, alph);

		ans = (ans + ct1*ct2) % M;
	}
	cout << ans << '\n';
	
	return 0;
}