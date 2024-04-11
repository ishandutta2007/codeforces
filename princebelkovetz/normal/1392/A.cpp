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
	cout << fixed << setprecision(4);
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		set <int> a;
		for (int i = 0; i < n; ++i) {
			int x; cin >> x;
			a.insert(x);
		}
		if (a.size() == 1) cout << n << '\n';
		else cout << "1\n";
	}
}