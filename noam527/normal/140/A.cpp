#include <iostream>
#include <vector>
#include <algorithm>
#define pi 3.14159265359
using namespace std;

int main() {
	double angle;
	int n, r, R, poss;
	cin >> n >> R >> r;
	if (r > R) {
		cout << "NO";
		return 0;
	}
	if (2 * r > R) {
		if (n == 1) cout << "YES";
		else cout << "NO";
		return 0;
	}
	if (n * acos(-2.0 * r * r / ((R - r) * (R - r)) + 1) * 180 / pi <= 360) cout << "YES";
	else cout << "NO";
	return 0;
}