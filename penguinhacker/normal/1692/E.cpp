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
		int n, s;
		cin >> n >> s;
		vector<int> pos;
		for (int i=0; i<n; ++i) {
			int x;
			cin >> x;
			if (x)
				pos.push_back(i);
		}
		if (s>pos.size()) {
			cout << "-1\n";
			continue;
		}
		int ans=1e9;
		for (int i=0; i+s-1<pos.size(); ++i)
			ans=min(ans, n-((i+s<pos.size()?pos[i+s]:n)-(i?pos[i-1]:-1)-1));
		cout << ans << "\n";
	}
	return 0;
}