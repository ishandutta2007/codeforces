#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;
void solve() {
	int n, ans; cin >> n;
	vector <int> a(n + 1), b(n + 1, 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	ans = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = i * 2; j <= n; j += i) {
			if (a[i] < a[j]) {
				b[j] = max(b[j], b[i] + 1);
				ans = max(ans, b[j]);
			}
		}
	}
	/*cout << endl;
	for (int i = 1; i <= n; ++i) {
		cout << b[i] << " ";
	}
	cout << endl;*/
	cout << ans << endl;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);
	int t; cin >> t;
	while (t--) {
		solve();
	}

}