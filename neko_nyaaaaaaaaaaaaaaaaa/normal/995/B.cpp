#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> a(2*n);
	for (int i = 0; i < 2*n; i++) {
		cin >> a[i];
	}
	
	int ans = 0;
	for (int k = 0; k < 2*n; k += 2) {
		int x = a[k];
		int y;
		for (int i = k+1; i < 2*n; i++) {
			if (a[i] == x) {
				y = i; break;
			}
		}
		
		for (int i = y; i-1 > k; i--) {
			swap(a[i], a[i-1]);
			ans++;
		}
	}
	
	/*for (int i = 0; i < 2*n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;*/
	cout << ans;
	
	return 0;
}