#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int n, a, b;
	cin >> n >> a >> b;
	int k = n/2;
	if (a <= k && b > k || a > k && b <= k) {cout << "Final!"; return 0;}
	
	int roundtot = 1;
	while (pow(2, roundtot) < n) {
		roundtot++;
	}
	int rd = 1;
	while (1) {
		n /= 2;
		if (a > n && b > n) {
			a -= n;
			b -= n;
		}
		k = n/2;
		if (a <= k && b > k || a > k && b <= k) {cout << roundtot - rd; return 0;}
		rd++;
	}
	
	return 0;
}