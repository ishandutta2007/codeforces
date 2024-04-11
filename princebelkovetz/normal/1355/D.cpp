#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define int long long
#define endl "\n";
using namespace std;

void solve() {
	int n, s;
	cin >> n >> s;
	if (s < 2 * n) {
		cout << "No";
		return;
	}
	else {
		cout << "Yes\n";
		for (int i = 0; i < n - 1; ++i) {
			cout << "2 ";
		}
		cout << s - n * 2 + 2 << endl;
		cout << 1;
	}
	return;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);
	int t;
	t = 1;
	while (t--) solve();
	return 0;
}