#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	if (a[n-1] - a[0] < 2) {
		cout << n << "\n";
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		return 0;
	}
	
	int val1 = a[0];
	int val2 = (a[n-1]+a[0])/2;
	int val3 = a[n-1];
	
	vector<int> c(3, 0);
	for (int i = 0; i < n; i++) {
		if (a[i] == val1) {c[0]++;}
		if (a[i] == val2) {c[1]++;}
		if (a[i] == val3) {c[2]++;}
	}
	
	int ans = c[0] + c[1] + c[2];
	
	if (c[1]/2 >= min(c[2], c[0])) {
		int k = c[1]/2;
		c[0] += k;
		c[2] += k;
		c[1] -= k*2;
		ans -= k*2;
	} else {
		int k = min(c[2], c[0]);
		c[1] += k*2;
		c[2] -= k;
		c[0] -= k;
		ans -= k*2;
	}
	
	cout << ans << "\n";
	for (int i = 0; i < c[0]; i++) {
		cout << val1 << " ";
	}
	for (int i = 0; i < c[1]; i++) {
		cout << val2 << " ";
	}
	for (int i = 0; i < c[2]; i++) {
		cout << val3 << " ";
	}
	
	return 0;
}