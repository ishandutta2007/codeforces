#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;
string s;
void solve() {
	cin >> n >> s;
	vector<vector<int>> cnt(2, vector<int>(2));
	for (int i = 0; i < n; ++i) {
		++cnt[(i + 1) % 2][(s[i] - '0') % 2];
	}
	if (n % 2 == 1) {
		cout << (cnt[1][1] > 0 ? 1 : 2) << "\n";
	}
	else {
		cout << (cnt[0][0] > 0 ? 2 : 1) << "\n";		
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}