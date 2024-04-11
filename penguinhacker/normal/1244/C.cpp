#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

ll n, p, d, w;

ll gcd(ll a, ll b) {
	if (a<b)
		swap(a, b);
	if (a%b==0)
		return b;
	return gcd(b, a%b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> p >> w >> d;
	if (p>w*n||p%gcd(w, d)) {
		cout << -1;
		return 0;
	}
	ll x=(p+w-1)/w;
	for (ll i=x; i<=n; ++i) {
		if (i*d>p)
			break;
		ll y=i*d;
		if ((p-y)%(w-d))
			continue;
		ll z=(p-y)/(w-d);
		if (z>i)
			continue;
		cout << z << ' ' << i-z << ' ' << n-i;
		return 0;
	}
	cout << -1;
	return 0;
}