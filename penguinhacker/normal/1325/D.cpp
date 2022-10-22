#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

ll a, b; //<XOR, SUM>

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;
	if (a==0&&b==0) {
		cout << 0;
	}
	else if (a>b||(a&1)!=(b&1)) {
		cout << -1;
	}
	else if (a==b) {
		cout << 1 << '\n';
		cout << a;
	}
	else {
		ll x=(b-a)/2;
		if ((a^x)+x==b) {
			cout << 2 << '\n';
			cout << (a^x) << ' ' << x;
		}
		else {
			cout << 3 << '\n';
			cout << x << ' ' << x << ' ' << a;
		}
	}
	return 0;
}