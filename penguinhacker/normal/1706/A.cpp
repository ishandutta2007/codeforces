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
		int n, m;
		cin >> n >> m;
		int cnt[50]={};
		for (int i=0; i<n; ++i) {
			int x;
			cin >> x, --x;
			x=min(x, m-1-x);
			++cnt[x];
		}
		string ans(m, 'B');
		for (int i=0; i<=m/2; ++i) {
			if (cnt[i])
				ans[i]='A';
			if (cnt[i]>1)
				ans[m-1-i]='A';
		}
		cout << ans << "\n";
	}
	return 0;
}