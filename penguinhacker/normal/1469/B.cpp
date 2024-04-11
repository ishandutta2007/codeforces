#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) {
		auto GetMax = [&]() {
			int n; cin >> n;
			int res = 0;
			int cur = 0;
			for (int i = 0; i < n; ++i) {
				int x; cin >> x;
				cur += x;
				res = max(res, cur);
			}
			return res;
		};
		int a = GetMax();
		int b = GetMax();
		cout << a + b << "\n";
	}
	return 0;
}