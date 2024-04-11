#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(ll n) {
	if (n == 1) return 1;
	if (n == 2) return 3;
	if (n == 3) return 4;
	if (n % 2 == 0) {
		return (2*solve(n/2) + n/2);
	} else {
		return (2*solve(n/2) + n/2 + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	ll n;
	while (cin >> n) {
		cout << solve(n-1) << endl;
	}
	
	return 0;
}