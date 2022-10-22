#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int a = abs(x1 - x2), b = abs(y1 - y2);
		if (a == 0 && b == 0) {
			cout << "0\n";
		}
		else if (a == 0 || b == 0) {
			cout << a + b << "\n";
		}
		else {
			cout << a + b + 2 << "\n";
		}
	}
	return 0;
}