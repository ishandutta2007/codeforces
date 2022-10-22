#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n, m, beatenBy[300001];
set<int> knights;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	memset(beatenBy, 0, sizeof(beatenBy));
	cin >> n >> m;
	for (int i=1; i<=n; ++i)
		knights.insert(i);
	while (m--) {
		int l, r, x;
		cin >> l >> r >> x;
		auto left = knights.lower_bound(l);
		auto right = knights.upper_bound(r);
		for (auto it=left; it!=right; ++it) {
			if (*it != x)
				beatenBy[*it]=x;
		}
		knights.erase(left, right);
		knights.insert(x);
	}
	
	for (int i=1; i<=n; ++i)
		cout << beatenBy[i] << ' ';
	return 0;
}