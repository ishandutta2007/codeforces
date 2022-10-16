#include <bits/stdc++.h>
using namespace std;

bool check(int ptr, int down, int up, int m) {
	if (up >= down) {
		return (ptr <= up && ptr >= down);
	} else {
		if (ptr >= 0 && ptr <= up) return 1;
		if (ptr < m && ptr >= down) return 1;
		return 0;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, m; cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int lo = 0, hi = m-1;
	while (lo < hi) {
		int mid = (lo + hi)/2;

		int ptr = 0;
		for (int i = 0; i < n; i++) {
			int down = a[i], up = (a[i] + mid) % m;
			while (ptr < m && !check(ptr, down, up, m)) {
				ptr++;
			}
			if (ptr == m) break;
		}

		if (ptr < m) {
			hi = mid;
		} else {
			lo = mid+1;
		}
	}
	cout << lo;

	return 0;
}