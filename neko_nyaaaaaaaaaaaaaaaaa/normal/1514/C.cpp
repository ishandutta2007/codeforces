#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<int> ans;
	int pd = 1;
	for (int i = 1; i < n; i++) {
		if (__gcd(i, n) == 1) {
			ans.push_back(i);
			pd = (pd*i) % n;
		}
	}
	if (pd != 1) {
		ans.erase(find(ans.begin(), ans.end(), pd));
	}

	cout << ans.size() << '\n';
	for (int i: ans) cout << i <<  ' ';

	return 0;
}