#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[100000], c[100000];
bool vis[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i] >> c[i];
	ll ans = accumulate(c, c + n, 0ll);
	int ind = min_element(a, a + n) - a;
	set<ar<int, 2>> s;
	for (int i = 0; i < n; ++i)
		if (i ^ ind)
			s.insert({a[i], a[i] + c[i]});
	int cur = a[ind] + c[ind];
	while(!s.empty()) {
		ar<int, 2> x = *s.begin();
		s.erase(s.begin());
		ans += max(0, x[0] - cur);
		cur = max(cur, x[1]);
	}
	cout << ans;
	return 0;
}