#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

ll n, a[100000], d[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	n--;
	for (int i=0; i<n; ++i) {
		d[i] = abs(a[i]-a[i+1]);
		if (i&1)
			d[i] *= -1;
	}
	
	ll best = 0;
	ll sum = 0;
	for (int i=0; i<n; ++i) {
		sum = max(sum+d[i], d[i]);
		d[i] *= -1;
		best = max(best, sum);
	}
	sum = 0;
	for (int i=0; i<n; ++i) {
		sum = max(sum+d[i], d[i]);
		best = max(best, sum);
	}
	
	cout << best;
	return 0;
}