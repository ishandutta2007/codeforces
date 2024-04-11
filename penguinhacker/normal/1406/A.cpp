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
		vector<int> cnt(101, 0);
		for (int i = 0; i < n; ++i) {
			int a;
			cin >> a;
			++cnt[a];
		}
		int ans = 0;
		for (int rep = 0; rep < 2; ++rep) {
			for (int i = 0; i <= 100; ++i) {
				if (cnt[i] == 0) {
					break;
				}
				++ans;
				--cnt[i];
			}
		}
		cout << ans << "\n";
	}
	return 0;
}