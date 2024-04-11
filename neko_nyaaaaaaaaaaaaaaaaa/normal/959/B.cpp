#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	
	ll n, m, k;
	cin >> n >> k >> m;
	map<string, int> s;
	string ss;
	for (int i = 1; i <= n; i++) {
		cin >> ss;
		s[ss] = i;
	}
	vector<ll> a(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	vector<ll> group(n+1);
	vector<ll> cost(n+1, 1e9);
	for (int i = 1; i <= k; i++) {
		int x, z;
		cin >> x;
		for (int j = 0; j < x; j++) {
			cin >> z;
			group[z] = i;
			cost[i] = min(cost[i], a[z]);
		}
	}
	
	ll ans = 0;
	for (int i = 1; i <= m; i++) {
		cin >> ss;
		ll ind = s[ss];
		ll gr = group[ind];
		ans += cost[gr];
	}
	cout << ans;
	
	return 0;
}