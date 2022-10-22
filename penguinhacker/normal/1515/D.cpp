#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, cl, cr;
map<int, int> l, r;

void solve() {
	cin >> n >> cl >> cr;
	l.clear(), r.clear();
	for (int i=0; i<cl; ++i) {
		int x;
		cin >> x;
		++l[x];
	}
	for (int i=0; i<cr; ++i) {
		int x;
		cin >> x;
		if (l[x])
			--l[x];
		else
			++r[x];
	}
	int ans=0, ls=0, rs=0;
	for (auto& x : l)
		ls+=x.second;
	for (auto& x : r)
		rs+=x.second;
	for (auto& x : l) {
		while(ls>rs&&x.second>=2)
			x.second-=2, ls-=2, ++ans;
	}
	for (auto& x : r) {
		while(rs>ls&&x.second>=2)
			x.second-=2, rs-=2, ++ans;
	}
	ans+=max(ls, rs);
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}