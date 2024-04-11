#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		if ((y-x)%(a+b) == 0) {
			cout << (y-x)/(a+b) << '\n';
		}
		else
			cout << -1 << '\n';
	}
	return 0;
}