#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	ll n, x, y;
	cin >> n >> x >> y;
	string s;
	cin >> s;
	ll seg0 = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			cnt++;
		} else {
			if (cnt) seg0++;
			cnt = 0;
		}
	}
	if (cnt) {seg0++;}
	
	if (seg0 == 0) {
		cout << 0; return 0;
	}
	
	ll ans1 = seg0 * y;
	ll ans2 = y + (seg0 - 1)*x;
	
	cout << min(ans1, ans2);
	
	return 0;
}