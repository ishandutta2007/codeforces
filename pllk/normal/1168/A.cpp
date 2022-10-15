#include <iostream>

using namespace std;

int n, m;
int a[303030];

bool ok(int x) {
	int f = 0;
	for (int i = 1; i <= n; i++) {
		int u = a[i];
		if (u >= f) {
			if (m-u+f > x) f = u;
		} else {
			if (u+x < f) return false;
		}
	}
	return true;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int k = -1;
	for (int b = m; b >= 1; b /= 2) {
		while (k+b <= m && !ok(k+b)) k += b;
	}
	cout << k+1 << "\n";
}