#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>

int n, k, ans=0, numSeated=0;
vector<pi> orderings;
vector<pair<pi, int>> v; //pay, and num of people
multiset<pi> tables;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	v.resize(n);
	for (int i=0; i<n; ++i) {
		cin >> v[i].first.second >> v[i].first.first;
		v[i].second=i+1;
	}
	sort(v.begin(), v.end(), [](pair<pi,int> a, pair<pi,int> b) 
			{return a.first.first!=b.first.first?a.first.first>b.first.first:a.first.second<b.first.second;} );
	cin >> k;
	for (int i=1, a; i<=k; ++i) {
		cin >> a;
		tables.insert({a, i});
	}
	for (int i=0; i<n; ++i) {
		if (tables.empty()||v[i].first.second>tables.rbegin()->first) continue;
		auto it = tables.lower_bound({v[i].first.second,0});
		orderings.emplace_back(v[i].second, it->second);
		tables.erase(it);
		ans+=v[i].first.first;
		numSeated++;
	}
	cout << numSeated << ' ' << ans << '\n';
	for (pi x:orderings)
		cout << x.first << ' ' << x.second << '\n';
	return 0;
}