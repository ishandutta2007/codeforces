#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a) {
		cin >> i;
	}
	sort(a.begin(), a.end());
	/*vector<int> b(n);
	auto can = [&](int x) {
		b.assign(n, -1);
		for (int i = 0; i < x; ++i) {
			b[2 * i + 1] = a[i];
		}
		for (int i = 0, j = x; i < n; ++i) {
			
		}
	};
	int l = 0, r = (n - 1) / 2;
	while(l < r) {
		int mid = (l + r + 1) / 2;

	}*/
	cout << (n - 1) /2 << "\n";
	vector<int> b(n, -1);
	for (int i = 0; i < (n - 1) / 2; ++i) {
		b[2 * i + 1] = a[i];
	}
	for (int i = 0, j = (n - 1) / 2; i < n; ++i) {
		if (b[i] != -1) {
			continue;
		}
		assert(j < n);
		b[i] = a[j++];
	}
	for (int i = 0; i < n; ++i) {
		if (i > 0) {
			cout << " ";
		}
		cout << b[i];
	}
	return 0;
}