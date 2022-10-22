#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n;

bool checkPrime(ll x) {
	for (ll i=2; i*i <= x; ++i)
		if (x%i == 0)
			return 0;
	return 1;
}

void solve() {
	ll x;
	cin >> x;
	ll s = sqrt(x);
	if (x>3 && s*s == x && checkPrime(s))
		cout << "YES\n";
	else
		cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	while (n--)
		solve();
	return 0;
}