#include <bits/stdc++.h>

using namespace std;

int main() {
	int n , m;
	cin >> n >> m;
	double res = 1000.;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		// cout << a << " " << b << endl;
		res = min(res, 1. * a / b);
	}
	printf("%0.10f\n", res * m);
	return 0;
}