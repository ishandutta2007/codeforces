#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <cassert>
#include <map>
#define int long long
#define ull unsigned long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
vector <vector <int>> okok(int n) {
	vector <vector <int>> res;
	for (int d = 1; d <= n / 2; d *= 2) {
		for (int i = 1; i <= n; i += i % d == 0 ? d + 1 : 1) {
			res.push_back({ i, i + d });
		}
	}
	return res;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int n; cin >> n;
	if (n == 1) {
		cout << 0;
		return 0;
	}
	int k = 1;
	while (k * 2 <= n)
		k *= 2;
	vector <vector <int>> got1 = okok(k);
	cout << got1.size() * 2 << '\n';
	for (auto x : got1) cout << x[0] << ' ' << x[1] << '\n';
	for (auto x : got1) cout << x[0] + n - k << ' ' << x[1] + n - k << '\n';
}