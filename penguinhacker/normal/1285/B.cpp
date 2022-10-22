#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n, a[100000], total;

void solve() {
	cin >> n;
	total = 0;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		total += a[i];
	}
	
	ll best = 0;
	ll sum = 0;
	for (int i=0; i<n-1; ++i) {
		sum = max(sum+a[i], a[i]);
		best = max(best, sum);
	}

	sum = 0;
	for (int i=1; i<n; ++i) {
		sum = max(sum+a[i], a[i]);
		best = max(best, sum);
	}
	
	cout << (total>best?"YES":"NO") << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    int t;
    cin >> t;
    while (t--)
		solve();

	return 0;
}