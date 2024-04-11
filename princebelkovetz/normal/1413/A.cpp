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
const int mod = 1e9 + 7;
int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(7);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector <int> a(n), ans(n);
		for (auto& x : a) cin >> x;
		for (int i = 0; i < n; i += 2)
			ans[i] = -a[i + 1], ans[i + 1] = a[i];
		
		for (auto x : ans) cout << x << ' ';
		cout << '\n';
	}
	return 0;
}