#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<iterator>
#include<map>
#include<deque>
#include<math.h>
#include <numeric> 
using namespace std;

#define int long long
#define pb push_back

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int l = -1, r = m;
	while (r - l > 1) {
		bool x = 1;
		int mid = (r + l) / 2;
		int p = 0;
		for (int i = 0; i < n; i++) {
			int l1 = v[i], r1 = v[i] + mid;
			if ((l1 <= p && p <= r1) || (l1 <= p + m && p + m <= r1)) {
				continue;
			}
			else {
				if (l1 < p) {
					x = 0;
					break;
				}
				else {
					p = l1;
				}
			}
		}
		if (!x) {
			l = mid;
		}
		else {
			r = mid;
		}
	}
	cout << r;
}