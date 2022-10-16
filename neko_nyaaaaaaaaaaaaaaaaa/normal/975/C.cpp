#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int n, q;
	cin >> n >> q;
	vector<ll> tmp(n+1), p(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> tmp[i];
		p[i] = p[i-1] + tmp[i];
	}
	cout << endl;
	
	vector<ll> a = tmp;
	
	// solve begins
	
	int pt = 1;
	ll arrow = 0;
	
	while (q--) {
		ll k;
		cin >> k;
		
		if (k + arrow >= p[n]) {
			cout << n << '\n';
			arrow = 0;
			pt = 1;
			continue;
		}
		
		arrow += k;
		
		cout << n - (upper_bound(p.begin() + 1, p.end(), arrow) - p.begin()) + 1 << '\n';
		
	}
	
	return 0;
}