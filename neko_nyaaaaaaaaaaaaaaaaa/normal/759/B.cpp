#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;
	vector<ll> a(n);
	cin >> a[0];
	
	int pt90 = 0, pt1440 = 0;
	
	vector<ll> ans(n, 20);
	
	for (int i = 1; i < n; i++) {
		cin >> a[i];
		
		while (a[i] - a[pt90] > 89) pt90++;
		while (a[i] - a[pt1440] > 1439) pt1440++;
		
		ans[i] = ans[i-1] + 20;
		ans[i] = min(ans[i], (pt90 ? ans[pt90 - 1] : 0) + 50LL);
		ans[i] = min(ans[i], (pt1440 ? ans[pt1440 - 1] : 0) + 120LL);
	}
	
	cout << "20\n";
	for (int i = 1; i < n; i++) {
		cout << ans[i] - ans[i-1] << '\n';
	}
	
	return 0;
}