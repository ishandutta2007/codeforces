#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k, a[2000], b[2000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> k >> n;
	for (int i = 0; i < k; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i) cin >> b[i];
	int pre = 0;
	set<int> ans;
	for (int i = 0; i < k; ++i) {
		pre += a[i];
		int start = b[0] - pre;
		if (ans.find(start) != ans.end()) continue;
		set<int> s(b, b + n);
		int x = start;
		for (int j = 0; j < k; ++j) {
			x += a[j];
			s.erase(x);
		}
		if (s.empty()) ans.insert(start);
	}
	cout << ans.size();
	return 0;
}