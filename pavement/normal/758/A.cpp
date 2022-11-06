#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, maxB = INT_MIN, s = 0;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		maxB = max(maxB, a[i]);
	}
	for (int i : a) {
		s += maxB - i;
	}
	cout << s;
}