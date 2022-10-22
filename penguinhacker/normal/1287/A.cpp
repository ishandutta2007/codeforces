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
		int ans=0;
		for (int i=0; i<n; ++i) {
			if (s[i]=='A')
				continue;
			int mx=6969;
			for (int j=i-1; ~j; --j)
				if (s[j]=='A')
					mx=min(mx, i-j);
			if (mx!=6969)
				ans=max(ans, mx);
		}
		cout << ans << "\n";
	}
	return 0;
}