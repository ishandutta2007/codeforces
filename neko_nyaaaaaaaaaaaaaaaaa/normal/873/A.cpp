#include <bits/stdc++.h>
using namespace std;

int main() {
	
	//Fuck you
	
	int n, k, x;
	cin >> n >> k >> x;
	vector<int> a(n);
	long ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	long j = a.size() - 1;
	while (k--) {
		ans += x;
		j--;
	}
	while (j > -1) {
		ans += a[j];
		j--;
	}
	cout << ans;
	
	//WA 4sure
	
	return 0;
}