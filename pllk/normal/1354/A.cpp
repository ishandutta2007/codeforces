#include <iostream>

using namespace std;

typedef long long ll;

int main() {
	int t;
	cin >> t;
	while (t--) {
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		ll u = 0;
		u += b;
		a -= b;
		if (a > 0) {
			ll f = c-d;
			if (f <= 0) {
				cout << "-1\n";
				continue;
			}
			if (a%f == 0) u += c*(a/f);
			else u += c*(a/f+1);
		}
		cout << u << "\n";
	}
}