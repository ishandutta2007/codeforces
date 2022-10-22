#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int t;
	cin >> t;
	const double PI = acos(-1);
	while(t--) {
		int n;
		cin >> n;
		double r = sin((PI - PI / n) / 2) / sin(PI / n);
		double ans = 2 * r * cos(PI / (4 * n));
		cout << ans << "\n";
	}
	return 0;
}