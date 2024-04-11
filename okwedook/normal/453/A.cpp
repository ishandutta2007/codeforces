#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

const int mod = 1e9 + 7;
const int N = 1e6 + 7;
#define ll long long
#define ld long double

int main() {
	int m, n;
	cin >> m >> n;
	ld ans = m;
	for (int i = 1; i < m; ++i) ans -= pow(i * 1.0 / m, n);
	cout << fixed << setprecision(12) << ans;
	return 0;
}