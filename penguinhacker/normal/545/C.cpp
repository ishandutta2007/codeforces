#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n, x[100000], h[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> x[i] >> h[i];

	if (n == 1) {
		cout << 1;
		return 0;
	}

	int cnt = 2;
	for (int i=1; i<n-1; ++i) {
		if (h[i]<x[i]-x[i-1])
			cnt++;
		else if (h[i]<x[i+1]-x[i]) {
			x[i] += h[i];
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}