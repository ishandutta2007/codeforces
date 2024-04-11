#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	ll n, m;
	cin >> n >> m;
	double ans = 1000000;
	while (n--) {
		double x, y;
		cin >> x >> y;
		if (x/y < ans) {ans = x/y;}
	}
	cout << fixed << setprecision(12) << ans*m;
	
	return 0;
}