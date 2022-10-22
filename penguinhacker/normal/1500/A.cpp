#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[200000], x[5000001], y[5000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j) {
			int s = a[i] + a[j];
			if (!x[s] && !y[s])
				x[s] = i, y[s] = j;
			else if (i != x[s] && i != y[s] && j != x[s] && j != y[s]) {
				cout << "YES\n" << i + 1 << " " << j + 1 << " " << x[s] + 1 << " " << y[s] + 1 << "\n";
				return 0;
			}
		}
	cout << "NO\n";
	return 0;
}