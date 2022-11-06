#include <bits/stdc++.h>
using namespace std;
#define int long long

main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c, d, e, f, tc = 0;
    cin >> a >> b >> c >> d >> e >> f;
    if (e > f) {
		int ct = min(a, d);
		a -= ct, d -= ct;
		tc += ct * e;
		ct = min(b, min(c, d));
		b -= ct, c -= ct, d -= ct;
		tc += ct * f;
	} else {
		int ct = min(b, min(c, d));
		b -= ct, c -= ct, d -= ct;
		tc += ct * f;
		ct = min(a, d);
		a -= ct, d -= ct;
		tc += ct * e;
	}
	cout << tc << '\n';
}