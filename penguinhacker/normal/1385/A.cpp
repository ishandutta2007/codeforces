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
		int x, y, z;
		cin >> x >> y >> z;
		if (x==y&&x>=z) {cout << "YES\n"; cout << x << ' ' << z << ' ' << z << '\n';}
		else if (x==z&&x>=y) {cout << "YES\n"; cout << y << ' ' << x << ' ' << y << '\n';}
		else if (y==z&&y>=x) {cout << "YES\n"; cout << x << ' ' << x << ' ' << y << '\n';}
		else {cout << "NO\n";}
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/