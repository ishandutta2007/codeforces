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
		string s;
		cin >> n >> s;
		vector<int> oc[2];
		for (int i=0; i<n; ++i)
			oc[s[i]-'0'].push_back(i);
		if (oc[0].empty()||oc[1].empty()||oc[0].back()<oc[1][0]) {
			cout << "0\n";
			continue;
		}
		vector<vector<int>> ans;
		while(oc[0].back()>oc[1][0]) {
			vector<int> cur;
			for (int i=0; i<min(oc[0].size(), oc[1].size()); ++i) {
				if (oc[0][oc[0].size()-1-i]<oc[1][i])
					break;
				cur.push_back(oc[0][oc[0].size()-1-i]);
				cur.push_back(oc[1][i]);
				swap(oc[0][oc[0].size()-1-i], oc[1][i]);
			}
			sort(cur.begin(), cur.end());
			ans.push_back(cur);
			sort(oc[0].begin(), oc[0].end());
			sort(oc[1].begin(), oc[1].end());
		}
		cout << ans.size() << "\n";
		for (vector<int>& v : ans) {
			cout << v.size();
			for (int i : v)
				cout << " " << i+1;
			cout << "\n";
		}
	}
	return 0;
}