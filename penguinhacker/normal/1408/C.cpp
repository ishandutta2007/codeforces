#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int t;
	cin >> t;
	while(t--) {
		int n, l;
		cin >> n >> l;
		vector<int> a(n + 2);
		a[n + 1] = l;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		vector<double> pre(n + 2), suf(n + 2);
		pre[0] = suf[n + 1] = 0;
		for (int i = 1; i <= n + 1; ++i) {
			pre[i] = pre[i - 1] + (a[i] - a[i - 1]) / (double)i;
			suf[n + 1 - i] = suf[n + 2 - i] + (a[n + 2 - i] - a[n + 1 - i]) / (double)i;
		}
		double ans = 0;
		int ind = -2;
		for (int i = 0; i <= n + 1; ++i) {
			if (pre[i] > suf[i]) {
				ind = i - 1;
				break;
			}
		}
		assert(0 <= ind && ind <= n + 1);
		assert(pre[ind] <= suf[ind]);
		//cout << ind << "\n";
		if (pre[ind] < suf[ind + 1]) {
			//cout << "HERE";
			double dist = a[ind + 1] - a[ind] - (suf[ind + 1] - pre[ind]) * (ind + 1);
			ans = suf[ind + 1] + dist / (n + 2);
		}
		else {
			double dist = a[ind + 1] - a[ind] - (pre[ind] - suf[ind + 1]) * (n + 1 - ind);
			ans = pre[ind] + dist / (n + 2);
		}
		cout << ans << "\n";
	}
	return 0;
}