#include <iostream>

using namespace std;

int n, m;
double a[1111];
double b[1111];

bool ok(double x) {
	double u = (m+x)/a[1];
	x -= u;
	if (x < 0) return false;
	for (int i = 2; i <= n; i++) {
		u = (m+x)/b[i];
		x -= u;
		if (x < 0) return false;
		u = (m+x)/a[i];
		x -= u;
		if (x < 0) return false;
	}
	u = (m+x)/b[1];
	x -= u;
	return x >= 0;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1 || b[i] == 1) {
			cout << "-1\n";
			return 0;
		}
	}
	double x = 0;
	double b = 1e9;
	for (int i = 1; i <= 1000; i++) {
		if (!ok(x+b)) x += b;
		b /= 2;
	}
	printf("%.9f\n",x);
}