#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, a[200000];
pair<int, int> H[200000]; //hero

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		vector<pair<int, int>> h;
		cin >> n;
		for (int i=0; i<n; ++i)
			cin >> a[i];
		cin >> m;
		for (int i=0; i<m; ++i)
			cin >> H[i].first >> H[i].second;
		sort(H, H+m, greater<pair<int, int>> ());
		h.push_back(H[0]);
		for (int i=1; i<m; ++i) {
			if (H[i].second>h.back().second)
				h.push_back(H[i]);
		}
		bool b=1;
		for (int i=0; i<n; ++i)
			if (a[i]>h[0].first) {
				b=0;
				break;
			}
		if (!b) {
			cout << "-1\n";
			continue;
		}
		int ans=0, l=0;
		while (l<n) {
			int r=l, MX=0;
			for (int i=0; i<h.size()&&r<n; ++i) {
				int p=h[i].first, e=h[i].second;
				if (MX>p)
					break;
				while(r<l+e&&r<n) {
					MX=max(MX, a[r]);
					if (p<a[r])
						break;
					++r;
				}
			}
			l=r;
			++ans;
		}
		cout << ans << '\n';
	}
	return 0;
}