#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>
#define int long long
#define endl "\n"
#define debug(x) cout << #x << " actually equals " << x << endl
int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}
using namespace std;
int mul(int a, int b, int m) {
	return (a * b) % m;
}
const int m = 1e9 + 7;
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(3);
	int h, w, ans = 1; cin >> h >> w;
	vector <int> rows(h), cols(w);
	for (auto & x: rows) cin >> x;
	for (auto& x : cols) cin >> x;
	vector <vector <int>> a(h, vector <int>(w, -1));
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < rows[i]; ++j) {
			a[i][j] = 0;
		}
		if (rows[i] < w) a[i][rows[i]] = 1;
	}

	for (int j = 0; j < w; ++j) {
		for (int i = 0; i < cols[j]; ++i) {
			if (a[i][j] == -1) a[i][j] = 0;
			else if (a[i][j] == 1) {
				cout << "0" << endl;
				return 0;
			}
		}
		if (cols[j] < h) {
			if (a[cols[j]][j] == -1) a[cols[j]][j] = 1;
			else if (a[cols[j]][j] == 0) {
				cout << "0" << endl;
				return 0;
			}
		}
	}
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) 
			if (a[i][j] == -1) ans = mul(ans, 2, m);
	}
	cout << ans << endl;
	return 0;
}