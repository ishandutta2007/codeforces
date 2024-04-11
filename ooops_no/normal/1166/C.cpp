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
	int n, cnt = 0;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v[i] = abs(a);
	}
	sort(v.begin(), v.end());
	for (int i = 1; i < n; i++) {
		if (v[i - 1] * 2 < v[i]) {
			continue;
		}
		if (v[0] * 2 >= v[i]) {
			cnt += i;
			continue;
		}
		int l = 0, r = i - 1;
		while (l + 1 < r) {
			int mid = (l + r) / 2;
			if (v[mid] * 2 < v[i]) {
				l = mid;
			}
			else {
				r = mid;
			}
		}
		cnt += i - r;
	}
	cout << cnt;
}