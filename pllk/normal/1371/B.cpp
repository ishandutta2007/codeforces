#include <iostream>

using namespace std;

typedef long long ll;

int main() {
	int t;
	cin >> t;
	while (t--) {
		ll n, r;
		cin >> n >> r;
		ll k = min(n-1,r);
		ll u = k*(k+1)/2;
		if (r >= n) u++;
		cout << u << "\n";
	}
}