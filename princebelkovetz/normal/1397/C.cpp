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
	int n; cin >> n;
	vector <int> a(n);
	for (auto& x : a) cin >> x;
	if (n == 1) {
		cout << "1 1\n";
		cout << -a[0] << '\n';
		cout << "1 1\n0\n1 1\n0";
		return 0;
	}
	int x = n - 1;
	cout << "1 " << n - 1 << '\n';
	for (int i = 0; i < n - 1; ++i) {
		int ost = (a[i] % n + n) % n;
		cout << (n - 1) * (ost) << ' ';
		a[i] += (n - 1) * (ost);
	}
	cout << '\n';
	cout << n << ' ' << n << '\n';
	cout << -a[n - 1] << '\n';
	a[n - 1] = 0;
	cout << "1 " << n << '\n';
	for (auto x : a) cout << -x << ' ';
}