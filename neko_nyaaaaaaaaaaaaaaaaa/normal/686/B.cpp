#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll tmp = 1;
	while (tmp) {
		tmp = 0;
		for (ll i = 0; i < n-1; i++) {
			if (a[i] > a[i+1]) {
				swap(a[i], a[i+1]);
				cout << i+1 << " " << i+2 << endl;
				tmp++;
			}
		}
	}
	
	return 0;
}