#include <iostream>

using namespace std;

typedef long long ll;

int main() {
	int t;
	cin >> t;
	while (t--) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (a < c) cout << 1;
		else cout << -1;
		cout << " ";
		if (a*b > c) cout << b;
		else cout << -1;
		cout << "\n";
	}
}