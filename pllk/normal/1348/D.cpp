#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void lol() {
	ll n;
	cin >> n;
	n--;
	ll x = 1;
	vector<ll> v;
	while (n) {
		ll f = x;
		if (2*x >= n) {
			x = n;
		} else {
			ll k = 0;
			for (ll b = x; b >= 1; b /= 2) {
				while (k+b <= 2*x && 2*(k+b) <= n) k += b;
			}
			x = k;
		}
		v.push_back(x-f);
		n -= x;
	}
	cout << v.size() << "\n";
	for (auto x : v) cout << x << " ";
	cout << "\n";
}

int main() {
	int t;
	cin >> t;
	while (t--) lol();
}