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
		set<string> st[9];
		vector<string> s(n);
		for (string& i : s) {
			cin >> i;
			st[i.size()].insert(i);
		}
		for (string i : s) {
			bool ok=0;
			for (int j=1; j<i.size(); ++j)
				if (st[j].find(i.substr(0, j))!=st[j].end()&&st[i.size()-j].find(i.substr(j))!=st[i.size()-j].end()) {
					ok=1;
					break;
				}
			cout << ok;
		}
		cout << "\n";
	}
	return 0;
}