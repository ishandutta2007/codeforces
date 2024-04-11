#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

void solve() {
	int n;
	cin >> n;
	map<int, vector<int>> mp;
	for (int i=0; i<n; ++i) {
		int x;
		cin >> x;
		mp[x].push_back(i);
	}
	ar<int, 4> ans={-1, -1, -1, -1};
	for (auto& x : mp) {
		vector<int> v=x.second;
		ans=max(ans, {1, x.first, v[0], v[0]});
		int cur=1, l=0, r=0;
		for (int i=1; i<v.size(); ++i) {
			int gap=v[i]-v[i-1]-1;
			if (cur+1-gap>1) {
				++r;
				cur=cur+1-gap;
				ans=max(ans, {cur, x.first, v[l], v[r]});
			} else {
				cur=1, l=r=i;
			}
		}
	}
	cout << ans[1] << " " << ans[2]+1 << " " << ans[3]+1 << "\n";
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