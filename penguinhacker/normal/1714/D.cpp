#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin >> q;
	while(q--) {
		string t;
		cin >> t;
		int n;
		cin >> n;
		vector<string> s(n);
		for (string& a : s)
			cin >> a;
		int cur=0;
		vector<ar<int, 2>> ans;
		while(cur<t.size()) {
			int best=-1;
			ar<int, 2> bb={-1, -1};
			for (int i=0; i<n; ++i)
				for (int j=cur; ~j&&j+s[i].size()>cur; --j) {
					//cout << i << " " << j<< endl;
					if (j+s[i].size()<=t.size()&&t.substr(j, s[i].size())==s[i]&&j+(int)s[i].size()>best) {
						best=j+s[i].size();
						bb={i+1, j+1};
					}
				}
			if (best<=cur)
				break;
			ans.push_back(bb);
			cur=best;
		}
		if (cur<t.size()) {
			cout << "-1\n";
			continue;
		}
		cout << ans.size() << "\n";
		for (auto [a, b] : ans)
			cout << a << " " << b << "\n";
	}
	return 0;
}