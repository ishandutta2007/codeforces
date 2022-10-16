#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> bitcnt(40);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 31; j++) {
			if (a[i] & (1LL << j)) bitcnt[j]++;
		}
	}

	long long ans = 0, anspos = 0;
	for (int i = 0; i < n; i++) {
		long long tmp = a[i];

		for (int j = 0; j < 31; j++) {
			if (a[i] & (1LL << j)) bitcnt[j]--;
		}

		for (int j = 0; j < 31; j++) {
			if (bitcnt[j]) {
				if (tmp & (1LL << j)) tmp ^= (1LL << j);
			} 
		}

		for (int j = 0; j < 31; j++) {
			if (a[i] & (1LL << j)) bitcnt[j]++;
		}

		if (tmp > ans) {
			ans = tmp;
			anspos = i;
		}
	}

	cout << a[anspos] << ' ';
	for (int i = 0; i < n; i++) {
		if (i != anspos) cout << a[i] << ' '; 
	}

	return 0;
}