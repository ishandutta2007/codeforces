#include <iostream>

using namespace std;

typedef long long ll;

int main() {
	int t;
	cin >> t;
	while (t--) {
		ll a, b, n;
		cin >> a >> b >> n;
		int c = 0;
		while (a <= n && b <= n) {
			if (a > b) swap(a,b);
			a += b;
			c++;
		}
		cout << c << "\n";
	}
}