#include <bits/stdc++.h>
using namespace std;

long long n, m, k;

long long getpg(long long p, long long inc) {
	long long c = p - inc;
	long long pg = (c - 1)/k;
	return pg;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> k;
	vector<long long> p(m);
	for (int i = 0; i < m; i++) {
		cin >> p[i];
	}
	reverse(p.begin(), p.end());
	
	long long ans = 0, inc = 0;
	while (p.size()) {
		ans++;
		
		long long c = p.back() - inc;
		long long pg = (c - 1)/k;
		
		while (p.size() && getpg(p.back(), inc) == pg) {
			p.pop_back();
		}
		inc = m - p.size();
	}
	cout << ans;

	return 0;
}