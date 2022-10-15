#include <iostream>

using namespace std;

typedef long long ll;

int main() {
	int t;
	cin >> t;
	while (t--) {
		ll a, b, n, m;
		cin >> a >> b >> n >> m;
		if (n+m <= a+b && m <= min(a,b)) cout << "YES\n";
		else cout << "NO\n";
	}
}