#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <cassert>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int tt; cin >> tt;
	while (tt --> 0) {
		int n; cin >> n;
		string s; cin >> s;
		int last = -1;
		for (int i = 0; i < n; ++i) {
			if ((s[i] - '0') + 1 != last) {
				cout << '1';
				last = (s[i] - '0') + 1;
			}
			else {
				cout << '0';
				last = (s[i] - '0');
			}
		}
		cout << '\n';
	}
	return 0;
}