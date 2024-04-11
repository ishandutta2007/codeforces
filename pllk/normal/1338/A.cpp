#include <iostream>

using namespace std;

typedef long long ll;

int n;
ll a[101010];

void lol() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	ll u = 0;
	for (int i = 2; i <= n; i++) {
		if (a[i] < a[i-1]) {
			u = max(u,a[i-1]-a[i]);
			a[i] = a[i-1];
		}
	}
	for (int b = 40; b >= 0; b--) {
		if (u&(1LL<<b)) {
			cout << b+1 << "\n";
			return;
		}
	}
	cout << 0 << "\n";
}

int main() {
	int t;
	cin >> t;
	while (t--) lol();
}