#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] >= 0)
			a[i] = -a[i] - 1;
	}
	if (n & 1) {
		int x = min_element(a, a + n) - a;
		a[x] = -a[x] - 1;
	}
	for (int i = 0; i < n; ++i)
		cout << a[i] << " ";
	return 0;
}