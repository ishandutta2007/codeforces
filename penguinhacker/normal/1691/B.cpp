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
		map<int, vector<int>> mp;
		for (int i=0; i<n; ++i) {
			int x;
			cin >> x;
			mp[x].push_back(i);
		}
		bool ok=1;
		for (auto x : mp)
			if (x.second.size()==1) {
				ok=0;
				break;
			}
		if (!ok)
			cout << "-1\n";
		else {
			vector<int> ans(n);
			for (auto x : mp) {
				vector<int> v=x.second;
				for (int i=0; i<v.size(); ++i)
					ans[v[i]]=v[(i+1)%v.size()];
			}
			for (int i : ans)
				cout << i+1 << " ";
			cout << "\n";
		}
	}
	return 0;
}