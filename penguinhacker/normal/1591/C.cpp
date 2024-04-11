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
		int n, k;
		cin >> n >> k;
		vector<int> v[2];
		for (int i=0; i<n; ++i) {
			int a;
			cin >> a;
			if (a>0)
				v[0].push_back(a);
			if (a<0)
				v[1].push_back(-a);
		}
		ll ans=0;
		int mx=0;
		for (int i : {0, 1}) {
			sort(v[i].begin(), v[i].end());
			if (v[i].size()) {
				mx=max(mx, v[i].back());
				for (int j=v[i].size()-1; j>=0; j-=k)
					ans+=2*v[i][j];
			}
		}
		cout << ans-mx << "\n";
	}
	return 0;
}