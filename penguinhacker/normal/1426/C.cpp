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
		int l = 0, r = 1e5;
		while(l < r) {
			int mid = (l + r) / 2;
			int x = mid / 2;
			int y = mid - x;
			int best = (x + 1) * (y + 1);
			if (best >= n) {
				r = mid;
			}
			else {
				l = mid + 1;
			}
		}
		cout << l << "\n";
	}
	return 0;
}