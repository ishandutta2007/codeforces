#include <bits/stdc++.h>
using namespace std;

vector<int> mobius(int n){
	vector<int> pr(n + 1);
	for (int i = 2; i <= n; i++) {
		if (pr[i] == 0) {
			for (int j = i; j <= n; j += i) {
				if (pr[j] == 0) {
					pr[j] = i;
				}
			}
		}
	}

	vector<int> mobius(n + 1);
	for(int i = 1; i <= n; ++i) {
		mobius[i] = 1;
		int x = i;
 
		while (x > 1) {
			int p = pr[x], cnt = 0;
			while (pr[x] == p) {
				cnt++;
				x /= p;
			}
 
			if (cnt >= 2) mobius[i] = 0;
			else mobius[i] *= -1;
		}
	}

	return mobius;
}

const long long M = 1e9+7;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;
	vector<int> d(100001);
	while (n--) {
		int x; cin >> x;
		for (int i = 1; i*i <= x; i++) {
			if (x % i == 0) {
				int a = x/i, b = i;
				if (a != b) {
					d[a]++; d[b]++;
				} else {
					d[a]++;
				}
			}
		}
	}

	vector<long long> p2(100001, 1);
	for (int i = 1; i <= 100000; i++) {
		p2[i] = (p2[i-1]*2) % M;
	}

	vector<int> mob = mobius(100000);
	long long ans = 0;
	for (int i = 1; i <= 100000; i++) {
		ans = (ans + mob[i]*(p2[d[i]] - 1)) % M;
	}
	if (ans < 0) ans += M;
	cout << ans << '\n';

	return 0;
}