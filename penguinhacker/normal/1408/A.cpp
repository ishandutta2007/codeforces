#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

void read(vector<int>& v) {
	for (int& i : v) {
		cin >> i;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n), b(n), c(n);
		read(a);
		read(b);
		read(c);
		vector<int> ans(n);
		ans[0] = a[0];
		for (int i = 1; i < n - 1; ++i) {
			ans[i] = ans[i - 1] == a[i] ? b[i] : a[i];
		}
		if (a[n - 1] != ans[n - 2] && a[n - 1] != ans[0]) {
			ans[n - 1] = a[n - 1];
		}
		if (b[n - 1] != ans[n - 2] && b[n - 1] != ans[0]) {
			ans[n - 1] = b[n - 1];
		}
		if (c[n - 1] != ans[n - 2] && c[n - 1] != ans[0]) {
			ans[n - 1] = c[n - 1];
		}
		for (int i : ans) {
			cout << i << " ";
		}
		cout << "\n";
	}
	return 0;
}