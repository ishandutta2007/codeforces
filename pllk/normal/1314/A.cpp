#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

int n;
ll a[202020];
ll t[202020];
vector<pair<ll,ll>> v;
multiset<pair<ll,ll>> s;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> t[i];
	for (int i = 1; i <= n; i++) {
		v.push_back({a[i],t[i]});
	}
	sort(v.begin(),v.end());
	ll u = 0;
	int k = 0;
	ll h = 0;
	while (k < n || s.size()) {
		if (s.size() == 0) {
			u = v[k].first;
		} else {
			u++;
		}
		while (k < n && v[k].first == u) {
			s.insert({v[k].second,v[k].first});
			k++;
		}
		auto it = s.rbegin();
		h += it->first*(u-it->second);
		s.erase(s.find(*s.rbegin()));
	}
	cout << h << "\n";
}