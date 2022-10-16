#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int n, k;
	cin >> n >> k;
	int ans = 1000000;
	int x;
	while (n--) {
		cin >> x;
		if (k % x == 0 && k/x < ans) {ans = k/x;}
	}
	cout << ans;
	
	return 0;
}