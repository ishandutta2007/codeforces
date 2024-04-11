#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;
vector<vector<int>> ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0, a; i<n; ++i) {
		cin >> a;
		if (ans.empty()||a<ans.back().back()) {
			vector<int> v={a};
			ans.push_back(v);
			continue;
		}
		int l=0, r=ans.size()-1;
		while(l<r) {
			int mid=(l+r)/2;
			if (a>ans[mid].back()) r=mid;
			else l=mid+1;
		}
		ans[l].push_back(a);
	}
	for (auto x : ans) {
		for (int i : x) cout << i << ' ';
		cout << '\n';
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/