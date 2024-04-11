#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

ll n, a, b;

ll gcd(ll x, ll y) {
	if (x<y)
		swap(x,y);
	if (y==0)
		return x;
	return gcd(y, x%y);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (ll i=1; i<=sqrt(n); ++i) {
		if (n%i != 0 || gcd(i, n/i) != 1)
			continue;
		a = i;
		b = n/i;
	}

	cout << a << ' ' << b;
	return 0;
}