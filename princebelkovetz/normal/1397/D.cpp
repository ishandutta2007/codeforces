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
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(7);
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		vector <int> a(n);
		for (auto& x : a) cin >> x;
		sort(a.begin(), a.end());
		if (n == 1) cout << "T";
		else if (n == 2) {
			if (a[0] == a[1]) cout << "HL";
			else cout << "T";
		}
		else {
			int sum = 0;
			for (auto x : a) sum += x;
			if (sum & 1 or a[n - 1] > sum - a[n - 1]) cout << "T";
			else cout << "HL";
		}
		cout << '\n';
	}
}