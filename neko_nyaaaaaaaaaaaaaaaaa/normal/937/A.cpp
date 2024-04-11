#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	vector<int> a(1000, 0);
	int n;
	cin >> n;
	int x;
	while (n--) {
		cin >> x;
		a[x] = 1;
	}
	int ans = 0;
	for (int i = 1; i <= 600; i++) {
		ans += a[i];
	}
	cout << ans;
	
	return 0;
}