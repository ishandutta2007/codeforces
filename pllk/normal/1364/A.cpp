#include <iostream>

using namespace std;

int a[101010];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		int s = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			s += a[i];
		}
		if (s%x != 0) {
			cout << n << "\n";
			continue;
		}
		int p = -1;
		int u = 0;
		for (int i = 1; i <= n; i++) {
			u += a[i];
			if (u%x != 0) {
				p = max(p,i);
				p = max(p,n-i);
			}
		}
		cout << p << "\n";
	}
}