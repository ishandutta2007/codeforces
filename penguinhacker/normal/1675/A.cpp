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
		int a, b, c, x, y;
		cin >> a >> b >> c >> x >> y;
		x-=a, y-=b;
		cout << (c>=max(x, 0)+max(y, 0)?"YES":"NO") << "\n";
	}
	return 0;
}