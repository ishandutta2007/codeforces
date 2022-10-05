#include <iostream>
typedef long long ll;
using namespace std;

int md = 1e9 + 7, n, m;

int pow(int b, int e) {
	int rtn = 1;
	while (e) {
		if (e & 1) rtn = (ll)rtn * b % md;
		e /= 2, b = (ll)b * b % md;
	}
	return rtn;
}

int main() {
	cin >> n >> m;
	cout << (2 * (n + 1 - m) * (ll)pow(2 * n + 2, m - 1) % md) << endl;
}