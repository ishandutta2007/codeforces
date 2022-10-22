#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> cnt(101);
		for (int i = 0; i < n; ++i) {
			int x; cin >> x;
			++cnt[x];
		}
		for (int i = 0; i <= 100; ++i)
			if (cnt[i])
				cout << i << " ", --cnt[i];
		for (int i = 0; i <= 100; ++i)
			while(cnt[i])
				cout << i << " ", --cnt[i];
		cout << "\n";
	}
	return 0;
}