#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, k, ans;
	cin >> n >> k;
	ans = k;
	vector<int> st(k);
	while (n--) {
		int a;
		cin >> a;
		ans = __gcd(ans, a);
	}
	
	cout << k/ans << '\n';
	for (int i = 0; i < k; i += ans) {
	      cout << i << " ";
	}
	
	return 0;
}