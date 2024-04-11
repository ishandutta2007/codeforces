#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	ll a, b; 
	cin >> a >> b;
	
	ll ar = a+b;
	vector<pair<ll, ll>> ans;
	for (ll i = 1; i*i <= ar; i++) {
		if (ar % i == 0) {
			ans.push_back({i, ar/i});
		}
	}
	vector<pair<ll, ll>> s1;
	for (ll i = 1; i*i <= a; i++) {
		if (a % i == 0) {
			s1.push_back({i, a/i});
		}
	}
	vector<pair<ll, ll>> s2;
	for (ll i = 1; i*i <= b; i++) {
		if (b % i == 0) {
			s1.push_back({i, b/i});
		}
	}
	
	ll r = 1e18;
	for (int i = ans.size() - 1; i >= 0; i--) {
		for (auto j: s1) {
			if (j.first <= ans[i].first && j.second <= ans[i].second) {
				cout << (ans[i].first + ans[i].second)*2;
				return 0;
			}
		}
		for (auto j: s2) {
			if (j.first <= ans[i].first && j.second <= ans[i].second) {
				cout << (ans[i].first + ans[i].second)*2;
				return 0;
			}
		}
	}
	
	return 0;
}