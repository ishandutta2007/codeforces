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
		int n, count = 0; cin >> n;
		vector <int> a(n), ok;
		for (auto& x : a) cin >> x;
		for (int i = 0; i < n; ++i) {
			if (a[i] != i + 1) {
				count++;
				ok.push_back(i);
			}
		}
		if (count == 0) cout << 0;
		else if (count == n) cout << 1;
		else {
			bool f = true;
			for (int i = 1; i < count; ++i) {
				if (ok[i] != ok[i - 1] + 1) {
					f = false; break;
				}
			}
			if (f) cout << 1;
			else cout << 2;

		}
		cout << endl;
	}
	return 0;
}