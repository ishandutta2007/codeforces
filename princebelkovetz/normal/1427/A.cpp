#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#define ull unsigned long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		int sum = 0;
		vector <int> a(n);
		for (auto& x : a) {
			cin >> x;
			sum += x;
		}
		if (sum == 0) {
			cout << "NO";
		}
		else if (sum > 0) {
			cout << "YES\n";
			sort(a.rbegin(), a.rend());
			for (auto x : a) cout << x << ' ';
		}
		else {
			cout << "YES\n";
			sort(a.begin(), a.end());
			for (auto x : a) cout << x << ' ';
		}
		cout << '\n';

	}
	return 0;
}