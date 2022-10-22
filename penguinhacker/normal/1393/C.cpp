#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;
vector<int> v;

bool ok(int x) {
	vector<int> use(n, -1), cnt(v.size());
	set<pair<int, int>, greater<pair<int, int>>> s;
	for (int i=0; i<v.size(); ++i) {
		s.insert({v[i], i});
		cnt[i]=v[i];
	}
	for (int i=0; i<n; ++i) {
		if (i-x-1>=0&&cnt[use[i-x-1]]>0)
			s.insert({cnt[use[i-x-1]], use[i-x-1]});
		if (s.empty()) return 0;
		use[i]=s.begin()->second;
		--cnt[s.begin()->second];
		s.erase(s.begin());
	}
	return 1;
}

void test_case() {
	cin >> n;
	map<int, int> mp;
	for (int i=0; i<n; ++i) {
		int a; cin >> a;
		mp[a]++;
	}
	v.clear();
	for (auto x: mp)
		v.push_back(x.second);
	int l=0, r=n-2;
	while(l<r) {
		int mid=(l+r+1)/2;
		if (ok(mid)) l=mid;
		else r=mid-1;
	}
	cout << l << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--)
		test_case();
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/