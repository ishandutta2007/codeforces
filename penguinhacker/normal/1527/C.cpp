#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		ll ans=0;
		map<int, vector<int>> mp;
		for (int i=0; i<n; ++i) {
			int x;
			cin >> x;
			mp[x].push_back(i);
		}
		for (auto& x : mp) {
			vector<int> v=x.second;
			int m=v.size();
			vector<ll> p(m);
			for (int i=0; i<m; ++i)
				p[i]=v[i]+1+(i?p[i-1]:0);
			for (int i=1; i<m; ++i)
				ans+=p[i-1]*(n-v[i]);
		}
		cout << ans << "\n";
	}
	return 0;
}