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
		vector <int> a(26);
		for (int i = 0; i < n; ++i) {
			string s; cin >> s;
			for (auto x : s) a[x - 'a']++;
		}
		bool c = true;
		for (auto x : a) {
			if (x % n) c = false;
		}
		if (c) cout << "YES";
		else cout << "NO";
		cout << '\n';
	}
}