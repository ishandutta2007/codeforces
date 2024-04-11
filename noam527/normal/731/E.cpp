#include <bits/stdc++.h>
using namespace std;

long long n, m, a[200002];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 1; i < n; i++) a[i] += a[i - 1];
	m = a[n - 1];
	for (int i = n - 2; i > 0; i--) m = max(m, a[i] - m);
	cout << m << endl;
}