#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 2; i <= n; i++) {
		if (n % i == 0) {ans++;}
	}
	cout << ans;
	
	return 0;
}