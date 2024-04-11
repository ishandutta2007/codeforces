#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	ll x, d, n = 1, c = 0;
	vector<ll> ans;
	cin >> x >> d;
	for (int b = 1; b <= x; b *= 2)
		if (x & b) {
			for (int i = 0; (1 << i) < b; i++) ans.push_back(n);
			n += d + 1;
			c++;
		}
	cout << ans.size() + c << endl;
	for (auto &i : ans) cout << i << " ";
	for (; c; c--, n += d + 1) cout << n << " ";
}