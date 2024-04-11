#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, x, m;
		cin >> n >> x >> m;
		vector<pair<int,int>> v;
		v.push_back({x,x});
		for (int i = 1; i <= m; i++) {
			int a, b;
			cin >> a >> b;
			for (auto u : v) {
				if (max(a,u.first) <= min(b,u.second)) {
					v.push_back({a,b});
					break;
				}
			}
		}
		sort(v.begin(),v.end());
		int u = 0;
		int r = 0;
		for (auto x : v) {
			if (x.first-1 > u) u = x.first-1;
			if (x.second > u) {
				r += x.second-u;
				u = x.second;
			}
		}
		cout << r << "\n";
	}
}