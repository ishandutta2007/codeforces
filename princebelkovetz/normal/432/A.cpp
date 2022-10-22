#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
using namespace std;
void solve() {
	int n, k, cnt = 0;
	cin >> n >> k;
	vector <int> a(n);
	for (int i = 0; i < n; ++i) { cin >> a[i]; }
	sort(a.begin(), a.end());
	for (int i = 0; i < n; ++i) {
		if (a[i] + k <= 5) ++cnt;
	}
	cout << cnt / 3;

}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);
	int t; t = 1;
	while (t--) {
		solve();
	}
}