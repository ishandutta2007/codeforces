/**
 * Niyaz Nigmatullin
 */

#include <bits/stdc++.h>

using namespace std;

struct base {
	int d;
	int g;
};

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);	
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<base> b(m);
	for (int i = 0; i < m; i++) {
		cin >> b[i].d >> b[i].g;
	}
	sort(b.begin(), b.end(), [](base const &a, base const &b) {
		return a.d < b.d;
	});
	vector<int> gold(m);
	for (int i = 0; i < m; i++) {
		if (i > 0) gold[i] = gold[i - 1];
		gold[i] += b[i].g;
	}
	for (int i = 0; i < n; i++) {
		if (i > 0) cout << ' ';
		int x = a[i];
		int left = -1;
		int right = m;
		while (left < right - 1) {
			int mid = (left + right) >> 1;
			if (b[mid].d > x) {
				right = mid;
			} else {
				left = mid;
			}
		}
		if (left >= 0) {
			cout << gold[left];
		} else {
			cout << 0;
		}
	}
	cout << endl;
}