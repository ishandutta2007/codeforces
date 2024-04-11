#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
const int N = 5e2 + 2;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(3);
	int n; cin >> n;
	vector <int> a(n), b(n);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;
	int good = 0, bad = 0;
	for (int i = 0; i < n; ++i) {
		good += bool(a[i] && !b[i]);
		bad += bool(!a[i] && b[i]);
	}
	if (!good) 
		cout << "-1\n";
	else 
		cout << (bad + 1 + good - 1) / good << '\n';
}