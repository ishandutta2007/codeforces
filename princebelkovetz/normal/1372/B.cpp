#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#define endl "\n"
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(3);
	int t; cin >> t;
	while (t --> 0) {
		int n; cin >> n;
		bool f = true;
		for (int i = 2; i * i <= n; ++i) {
			if (n % i == 0) {
				cout << n / i << " " << n - n / i << endl;
				f = false; break;
			}
		}
		if (f) cout << 1 << " " << n - 1 << endl;
	}
	return 0;
}