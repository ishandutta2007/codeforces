#include <iostream>

using namespace std;

typedef long long ll;

int c[20];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		for (int b = 0; b < 20; b++) {
			if (x&(1<<b)) c[b]++;
		}
	}
	ll s = 0;
	for (int i = 1; i <= n; i++) {
		ll x = 0;
		for (int b = 0; b < 20; b++) {
			if (c[b]) {
				x |= (1<<b);
				c[b]--;
			}
		}
		s += x*x;
	}
	cout << s << "\n";
}