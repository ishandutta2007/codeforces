#include <bits/stdc++.h>
using namespace std;

const long long M = 1e9+7;
const int MAX = 10000000;

int mobius[MAX + 1], dv[MAX + 1];
long long p2[MAX + 1];

void init() {
	p2[0] = 1; 
	for (int i = 1; i <= MAX; i++) {
		mobius[i] = 1;
		p2[i] = (p2[i-1]*2) % M;
	}

	for (long long i = 2; i <= MAX; i++) {
		if (!dv[i]) {
			for (int j = i; j <= MAX; j += i) {
				mobius[j] *= -1;
				dv[j] = i;
			} 

			for (long long j = i*i; j <= MAX; j += i*i) {
				mobius[j] = 0;
			} 
		}
	}
}

int cc[MAX + 1], cnt[MAX + 1];

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	init();
	
	int n; cin >> n;
	vector<int> a(n);
	for (int &i: a) {
		cin >> i;
		cc[i]++;
	}

	for (int i = 1; i <= MAX; i++) {
		for (int j = i; j <= MAX; j += i) {
			cnt[i] += cc[j];
		}
	}

	long long pre_ans = 0;
	for (int i = 1; i <= MAX; i++) {
		pre_ans = (pre_ans + mobius[i]*(p2[cnt[i]] - 1)) % M;
	}
	long long non_co = ((p2[n] - 1) - pre_ans) % M;
	// cout << non_co << '\n';
	long long ans = 0;
	for (int f: a) {
		vector<int> dvs;
		while (f > 1) {
			int p = dv[f];
			dvs.push_back(p);

			while (f % p == 0) f /= p;
		}

		int sz = dvs.size(); long long tmp = non_co;
		for (int m = 1; m < (1 << sz); m++) {
			long long c = 1;
			for (int i = 0; i < sz; i++) {
				if (m & (1 << i)) {
					c *= dvs[i];
				}
			}
			tmp = (tmp + mobius[c]*(p2[cnt[c]] - 1)) % M;
		}
		ans = (ans + tmp) % M;
	}
	if (ans < 0) ans += M;
	cout << ans << '\n';

	return 0;
}