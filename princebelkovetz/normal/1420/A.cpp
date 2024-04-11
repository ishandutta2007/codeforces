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
#define int long long
#define ull unsigned long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
signed main() {
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		vector <int> a(n), b(n);
		for (auto& x : a) cin >> x;
		b = a;
		sort(b.rbegin(), b.rend());
		set <int> c;
		for (auto x : b) c.insert(x);
		if (b == a and c.size() == n) {
			cout << "NO";
		}
		else cout << "YES";
		cout << '\n';
	}
	return 0;
}