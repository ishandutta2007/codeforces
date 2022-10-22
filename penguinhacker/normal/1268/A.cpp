#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	string s;
	cin >> n >> k >> s;
	string ans(n, 0);
	for (int i = 0; i < n; ++i) ans[i] = s[i % k];
	if (ans >= s) {cout << n << "\n" << ans; return 0;}
	for (int i = k - 1; i >= 0; --i) {
		if (ans[i] == '9') ans[i] = '0';
		else {++ans[i]; break;}
	}
	for (int i = k; i < n; ++i) ans[i] = ans[i % k];
	cout << n << "\n" << ans;
	return 0;
}