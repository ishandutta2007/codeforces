#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	long rp, d, n;
	long count = 0;
	cin >> rp >> d >> n;
	float upbound = sqrt(rp*rp);
	float downbound = sqrt((rp-d)*(rp-d));
	for (int i = 0; i < n; i++) {
		long x, y, r;
		cin >> x >> y >> r;
		float dist = sqrt(x*x + y*y);
		if ((dist + r) <= upbound && (dist - r) >= downbound) {count++;}
	}
	cout << count;
}