#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		vector<int> pos;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			if (a[i]) {
				pos.push_back(i);
			}
		}
		assert(!pos.empty());
		int ans = pos.back() - pos[0] + 1 - pos.size();
		cout << ans << "\n";
	}
	return 0;
}