#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<iterator>
#include<map>
#include<deque>
#include<math.h>
using namespace std;

#define int long long
#define pb push_back

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		vector<int> v(m), v1;
		for (int j = 0; j < m; j++) {
			cin >> v[j];
		}
		sort(v.begin(), v.end());
		int res = v[0] * v[m - 1];
		for (int i = 2; i <= sqrt(res); i++) {
			if (res % i == 0) {
				if (i == res / i) {
					v1.pb(i);
					continue;
				}
				v1.pb(i);
				v1.pb(res / i);
			}
		}
		sort(v1.begin(), v1.end());
		if (v1 == v) {
			cout << res << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
}