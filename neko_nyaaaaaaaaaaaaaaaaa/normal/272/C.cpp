#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios::sync_with_stdio(0);
	
	int n; cin >> n;
	vector<ll> a(n+1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	int m; cin >> m;
	ll cur = a[1];
	while (m--) {
		ll w, h;
		cin >> w >> h;
		cout << max(cur, a[w]) << '\n';
		cur = max(cur + h, a[w] + h);
	}
	
	return 0;
}