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
		int n, l, r, k;
		cin >> n >> l >> r >> k;
		vector<int> a;
		for (int i=0; i<n; ++i) {
			int x;
			cin >> x;
			if (l<=x&&x<=r)
				a.push_back(x);
		}
		sort(a.begin(), a.end());
		int ans=0;
		for (int i : a) {
			if (i>k)
				break;
			++ans;
			k-=i;
		}
		cout << ans << "\n";
	}
	return 0;
}