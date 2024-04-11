#include <bits/stdc++.h>
using namespace std;

const int MAX = 500000;

vector<int> prime(MAX + 5);
vector<int> divisor[MAX + 5];
vector<int> mobius(MAX + 5, 1);

void init() {
	for (int i = 1; i <= MAX; i++) {
		for (int j = i; j <= MAX; j += i) {
			divisor[j].push_back(i);
		}
	}
	for (int i = 2; i <= MAX; i++) {
		if (!prime[i]) {
			for (int j = i; j <= MAX; j += i) {
				prime[j] = (j != i);
				mobius[j] *= -1;
				if (j % (1LL*i*i) == 0) mobius[j] = 0;
			}
		}
	}
}

long long ans;
vector<int> cnt(MAX + 5);

void add(int x) {
	for (int i: divisor[x]) {
		if (mobius[i]) {
			ans += cnt[i] * mobius[i];
			cnt[i]++;
		}
	}
}

void remove(int x) {
	for (int i: divisor[x]) {
		if (mobius[i]) {
			cnt[i]--;
			ans -= cnt[i] * mobius[i];
		}
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	init();
	
	int n, q; cin >> n >> q;
	vector<int> a(n+1);
	vector<int> beer(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> beer[i];
	}

	while (q--) {
		int x; cin >> x;
		if (a[x]) {
			remove(beer[x]); a[x] = 0;
		} else {
			add(beer[x]); a[x] = 1;
		}
		cout << ans << '\n';
	}

	return 0;
}