#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s; cin >> s;
	vector<int> a;
	for (char c: s) a.push_back(c-'a'+1);
	int sum = accumulate(begin(a), end(a), 0);

	int res;
	if (size(s)%2 == 0) {
		res = sum;
	} else {
		res = sum - 2*min(a[0],a.back());
	}
	
	if (res > 0) {
		cout << "Alice" << ' ' << res << '\n';
	} else {
		cout << "Bob" << ' ' << -res << '\n';
	}
}

int main() {
	int tc; cin >> tc;
	while (tc--) solve();
}