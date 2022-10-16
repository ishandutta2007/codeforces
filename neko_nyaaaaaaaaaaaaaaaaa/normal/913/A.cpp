#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	ll n, m;
	cin >> n >> m;
	if (n > 40) {cout << m; return 0;}
	ll mm = 1;
	for (ll i = 0; i < n; i++) {
		mm *= 2;
	}
	cout << m % mm;
	
	return 0;
}