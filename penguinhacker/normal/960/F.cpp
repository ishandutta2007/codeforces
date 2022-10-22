#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, m, ans;
map<int, int> mp[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	while(m--) {
		int a, b, w;
		cin >> a >> b >> w, --a, --b;
		auto it=mp[a].lower_bound(w);
		int l=it==mp[a].begin()?1:1+prev(it)->second;
		ans=max(ans, l);
		it=mp[b].upper_bound(w);
		if (it!=mp[b].begin()&&prev(it)->second>=l)
			continue;
		if (it!=mp[b].begin()&&prev(it)->first==w)
			--it;
		it=mp[b].insert(it, {w, l}), it->second=l;
		for (; next(it)!=mp[b].end()&&next(it)->second<=l; mp[b].erase(next(it)));
	}
	cout << ans;
	return 0;
}