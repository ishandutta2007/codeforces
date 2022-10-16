#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ans = 0;

void solve(vector<pair<ll, ll>> a) {
	int n = a.size();
	sort(a.begin(), a.end());
	multiset<ll> s1, s2;
	for (int i = 0; i < n; i++) {
		s2.insert(a[i].second);
	}
	int i, j;
	for (i = 0; i < n; i = j) {
		for (j = i; j < n && a[i].first == a[j].first; j++) {
			s1.insert(a[j].second);
			s2.erase(s2.find(a[j].second));
		}
		ll l = -1e9;
		ll r = 1e9;
		if(s1.size()) {
			auto it = s1.begin();
			l = max(l, *it);
			it = s1.end();
			it--;
			r = min(r, *it);
		}
		if(s2.size()) {
			auto it = s2.begin();
			l = max(l, *it);
			it = s2.end();
			it--;
			r = min(r, *it);
		}
		
		if (j < n) {ans += (a[j].first - a[i].first) * max(r-l, 0LL);}
	}
	
	// sweep line algorithm
}

int main() {
	ios::sync_with_stdio(0);
	
	vector<pair<ll, ll>> o, e;
	int n; ll a, b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if ((a+b) % 2) {o.push_back({a+b, a-b});}
		else {e.push_back({a+b, a-b});}
	}
	solve(o); solve(e);
	
	cout << ans/4;
	
	return 0;
}