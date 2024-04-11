#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n; string s;
	cin >> s;
	n = s.size();
	
	bool st = 1;
	for (int i = 1; i < n; i++) {
		if (s[i] == s[i-1]) {st = 0; break;}
	}
	if (st) {cout << n; return 0;}
	
	vector<int> c;
	int cur = 1;
	for (int i = 1; i < n; i++) {
		if (s[i] == s[i-1]) {
			c.push_back(cur);
			cur = 1;
		} else {
			cur++;
		}
	}
	c.push_back(cur);
	
	int ans = *max_element(c.begin(), c.end());
	
	if (s[0] != s[n-1]) {
		ans = max(ans, c[0] + c.back());
	}
	cout << ans;
	return 0;
}