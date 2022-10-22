#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) {
		int n, k; cin >> n >> k;
		vector<pair<int, int>> p(n);
		for (int i = 0; i < n; ++i) {
			cin >> p[i].first >> p[i].second;
		}
		bool can = 0;
		for (int i = 0; i < n; ++i) {
			bool b = 1;
			for (int j = 0; j < n; ++j) {
				b &= abs(p[i].first - p[j].first) + abs(p[i].second - p[j].second) <= k;
			}
			can |= b;
		}
		cout << (can ? 1 : -1) << "\n";
	}
	return 0;
}