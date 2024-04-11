#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, cur=-1;
ll sum=0, ans=0;
vector<pair<int, int>> v;
multiset<int> s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	v.resize(n);
	for (int i=0; i<n; ++i) cin >> v[i].first;
	for (int i=0; i<n; ++i) cin >> v[i].second;
	sort(v.rbegin(), v.rend());

	auto add=[&]() { //add to set
		assert(v.size());
		s.insert(v.back().second);
		cur=v.back().first;
		sum+=v.back().second;
		v.pop_back();
	};

	while(v.size()||s.size()) {
		if (s.empty()) add();
		else ++cur;
		while(v.size()&&v.back().first<=cur) {
			assert(v.back().first==cur);
			add();
		}
		assert(s.size());
		sum-=*s.rbegin();
		s.erase(prev(s.end()));
		ans+=sum;
	}
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/