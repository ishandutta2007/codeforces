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
#define int long long
#define ull unsigned long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(7);
	int n; cin >> n;
	vector <int> a(n), b;
	for (auto& x : a) cin >> x;
	sort(a.begin(), a.end());
	b.push_back(a.back());
	int last = n - 2, i = 0;
	while (last > i) {
		b.push_back(a[i++]);
		b.push_back(a[last--]);
	}
	if (n % 2 == 0) b.push_back(a[i]);
	cout << (n - 1) / 2 << '\n';
	for (auto x : b) cout << x << ' ';
	return 0;
}