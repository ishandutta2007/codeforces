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
		string a, b;
		cin >> n >> a >> b;
		if (a[0]!=b[0]||a[n-1]!=b[n-1]) {
			cout << "-1\n";
			continue;
		}
		auto Get=[&](string s) {
			vector<ar<int, 2>> segs;
			for (int i=0; i<n; ++i) {
				if (s[i]=='0')
					continue;
				int j=i;
				for (; j+1<n&&s[j+1]=='1'; ++j);
				segs.push_back({i, j});
				i=j;
			}
			return segs;
		};
		vector<ar<int, 2>> v1=Get(a), v2=Get(b);
		if (v1.size()!=v2.size()) {
			cout << "-1\n";
			continue;
		}
		ll ans=0;
		for (int i=0; i<v1.size(); ++i)
			ans+=abs(v1[i][0]-v2[i][0])+abs(v1[i][1]-v2[i][1]);
		cout << ans << "\n";
	}
	return 0;
}