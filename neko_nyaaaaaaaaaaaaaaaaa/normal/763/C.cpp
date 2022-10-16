#include <bits/stdc++.h>
using namespace std;

long long modpow(long long n, long long k, long long MOD) {
	long long ans = 1; n %= MOD;
	while (k > 0) {
		if (k & 1) ans = (ans*n) % MOD;
		k >>= 1; n = (n*n) % MOD;
	}
	return ans;
}

#define int long long

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int m, n; cin >> m >> n;
	set<int> a;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		a.insert(x);
	}
	if (n == 1) {
		cout << *a.begin() << ' ' << 1 << '\n';
		exit(0);
	} else if (n == m) {
		cout << "0 1\n";
		exit(0);
	} else if (n == m-1) {
		for (int i = 0; i < m; i++) {
			if (a.find(i) == a.end()) {
				cout << (i+1)%m << ' ' << 1 << '\n';
				exit(0);
			}
		}
	}

	int comple = 0;
	set<int> b;
	if (m < 2*n) {
		for (int i = 0; i < m; i++) {
			if (a.find(i) == a.end()) b.insert(i);
		}
		swap(a, b);
		comple = 1;
		n = a.size();
	}

	int diff = *a.rbegin() - *a.begin();
	int cnt = n;
	for (auto it = a.begin(); it != a.end(); it++) {
		cnt -= (a.find((*it + diff) % m) != a.end());
	}
	diff = (diff * modpow(cnt, m-2, m)) % m;

	if (comple) swap(a, b);
	b = a;

	int st = *a.begin();
	a.erase(a.begin());
	while (1) {
		int nxt = ((st - diff) % m + m) % m;
		if (a.find(nxt) == a.end()) break;
		st = nxt; a.erase(a.find(st));
	}

	int cur = st;
	while (1) {
		if (b.find(cur) == b.end()) {
			cout << "-1\n";
			exit(0);
		}
		b.erase(b.find(cur));
		if (b.empty()) break;
		cur = (cur + diff) % m;
	}
	cout << st << ' ' << diff << '\n';

 	return 0;
}