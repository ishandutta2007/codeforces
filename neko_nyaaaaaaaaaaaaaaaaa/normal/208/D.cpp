#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;
	vector<int> p(5), ans(5), a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < 5; i++) cin >> p[i];
	int cr = 0;
	
	for (int x: a) {
		cr += x;
		
		for (int i = 4; i >= 0; i--) {
			while (p[i] <= cr) {
				ans[i] += cr/p[i];
				cr -= (cr/p[i])*p[i];
			}
		}
	}
	
	for (int i = 0; i < 5; i++) cout << ans[i] << " ";
	cout << endl << cr;
	 
	return 0;
}