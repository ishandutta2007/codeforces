#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int t;
	cin >> t;
	while (t--) {
		int n, k, x;
		cin >> n >> k;
		vector<int> a(k+1, 0);
		for (int i = 1; i <= k; i++) {
			cin >> a[i];
		}
		a.push_back(n);
		int ans = max(n - a[k], a[1]-1);
		for (int i = 1; i < k; i++) {
			ans = max(ans, (a[i+1] - a[i])/2);
		}
		cout << ans+1 << "\n";
		
	}
	
	return 0;
}