#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, k, p, need[2];
vector<vector<int>> oc[2], ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k >> p;
	need[0]=p, need[1]=k-p;
	for (int i=0; i<n; ++i) {
		int x;
		cin >> x;
		oc[x%2].push_back({x});
	}
	while(oc[0].size()<need[0]&&oc[1].size()>=2) {
		int x=oc[1].back()[0];
		oc[1].pop_back();
		int y=oc[1].back()[0];
		oc[1].pop_back();
		oc[0].push_back({x, y});
	}
	if (oc[0].size()<need[0]||oc[1].size()<need[1]||(oc[1].size()-need[1])%2) {
		cout << "NO";
		return 0;
	}
	for (int i=0; i<2; ++i)
		for (int j=0; j<need[i]; ++j)
			ans.push_back(oc[i].back()), oc[i].pop_back();
	for (int i=0; i<2; ++i)
		for (auto& v : oc[i])
			for (int j : v)
				ans[0].push_back(j);
	cout << "YES\n";
	for (auto& v : ans) {
		cout << v.size();
		for (int i : v)
			cout << " " << i;
		cout << "\n";
	}
	return 0;
}