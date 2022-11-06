#include <bits/stdc++.h>
using namespace std;
#define int long long

int m[100005], o[100005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> m[i];
	int mtc = 0, ans = -1;
	for (int i = 1; i <= n; i++) {
		int tc = m[i];
		for (int j = i - 1, lim = m[i]; j >= 1; j--) {
			lim = min(lim, m[j]);
			tc += lim;
		}
		for (int j = i + 1, lim = m[i]; j <= n; j++) {
			lim = min(lim, m[j]);
			tc += lim;
		}
		if (tc >= mtc) {
			mtc = tc;
			ans = i;
		}
	}
	for (int j = ans - 1, lim = m[ans]; j >= 1; j--) {
		lim = min(lim, m[j]);
		o[j] = lim;
	}
	for (int j = ans + 1, lim = m[ans]; j <= n; j++) {
		lim = min(lim, m[j]);
		o[j] = lim;
	}
	o[ans] = m[ans];
	for (int i = 1; i <= n; i++) cout << o[i] << ' ';
	cout << '\n';
}