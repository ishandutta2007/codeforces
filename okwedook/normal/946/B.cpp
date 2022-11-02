#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ll a, b;
	cin >> a >> b;
	while (a > 0 && b > 0) {
		if (a >= b * 2) a %= b * 2;
		else if (b >= a * 2) b %= a * 2;
		else break;
	}
	cout << a << ' ' << b;
	return 0;
}