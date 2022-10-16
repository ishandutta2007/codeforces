#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int ans = 0;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
	      int x;
	      cin >> x;
	      ans += x;
	}
	while (n--) {
	      int x;
	      cin >> x;
	      ans -= x;
	}
	cout << (ans >= 0 ? "Yes" : "No");
	
	return 0;
}