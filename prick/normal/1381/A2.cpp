#include <bits/stdc++.h>

using namespace std;

#define int long long
#define sz(x) ((int) (x).size())

void solve() {
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	
	vector<int> ans;
	int cur = 0;
	for (int it = n - 1; it >= 0; --it) {
		int x = a[cur] - '0';
		int y = b[it] - '0';
		if ((n - it) % 2 == 0) {
			x ^= 1;
		}
		if (x == y) {
			ans.push_back(1);
		}
		ans.push_back(it + 1);
		
		if ((n - it) % 2 == 0) {
			cur -= it;
		} else {
			cur += it;
		}
	}
	cout << sz(ans);
	for (auto i: ans) {
		cout << ' ' << i;
	}
	cout << '\n';
}

signed main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}
}