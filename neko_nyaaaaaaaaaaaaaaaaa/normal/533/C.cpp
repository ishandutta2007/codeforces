#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a+b <= max(c, d)) cout << "Polycarp";
	else if (a <= c && b <= d) cout << "Polycarp";
	else cout << "Vasiliy";

	return 0;
}