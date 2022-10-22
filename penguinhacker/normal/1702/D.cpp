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
		string s;
		int p;
		cin >> s >> p;
		int cost=0;
		vector<ar<int, 2>> pos;
		for (int i=0; i<s.size(); ++i) {
			cost+=s[i]-'a'+1;
			pos.push_back({s[i]-'a'+1, i});
		}
		vector<bool> vis(s.size());
		sort(pos.rbegin(), pos.rend());
		for (int i=0; cost>p; ++i) {
			cost-=pos[i][0];
			vis[pos[i][1]]=1;
		}
		for (int i=0; i<s.size(); ++i)
			if (!vis[i])
				cout << s[i];
		cout << "\n";
	}
	return 0;
}