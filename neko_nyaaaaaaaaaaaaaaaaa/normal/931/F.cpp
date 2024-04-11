#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	
	int n, m, l, r;
	cin >> n >> m;
	vector<int> a(100007, 0);
	while (n--) {
		cin >> l >> r;
		a[l]++;
		a[r+1]--;
	}
	for (int i = 1; i <= m; i++) {
		a[i] += a[i-1];
	}
	
	vector<int> LIS(100007, 0);
	vector<int> LISRev(100007, 0);
	vector<int> d(100007, 0);
	int M = 0;
	
	for (int i = 1; i <= m; i++) {
		int j = upper_bound(d.begin() + 1, d.begin() + M + 1, a[i]) - d.begin();
		LIS[i] = j;
		d[j] = a[i];
		M = max(M, j);
	}
	
	M = 0;
	for (int i = m; i; i--) {
		int j = upper_bound(d.begin() + 1, d.begin() + M + 1, a[i]) - d.begin();
		LISRev[i] = j;
		d[j] = a[i];
		M = max(M, j);
	}
	
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		ans = max(ans, LIS[i] + LISRev[i] - 1);
	}
	
	cout << ans;
	
	return 0;
}