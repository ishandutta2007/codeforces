#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int n, p, l, r;
	cin >> n >> p >> l >> r;
	if (l == 1 && r == n) {cout << 0; return 0;}
	if (l == 1) {
		cout << abs(r-p)+1; return 0;
	}
	if (r == n) {
		cout << abs(p-l)+1; return 0;
	}
	int ans = abs(r - l);
	ans += min(abs(r-p), abs(p-l)) + 2;
	cout << ans;
	
	return 0;
}