#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll M = 1e9+7;

int main() {
	ios::sync_with_stdio(0);
	
	string s;
	cin >> s;
	ll ans = 0;
	ll cur = 0;
	for (int i = s.size()-1; i >= 0; i--) {
		if (s[i] == 'a') {
			ans += cur;
			cur *= 2;
			cur %= M;
			ans %= M;
		} else {cur = (cur + 1)%M;}
	}
	cout << ans;
	
	return 0;
}