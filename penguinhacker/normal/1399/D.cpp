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
		int n; cin >> n;
		string s; cin >> s;
		int ans=0;
		vector<int> part(n), seg[2];
		for (int i=0; i<n; ++i) {
			int c=s[i]-'0';
			if (seg[c].empty()) seg[c].push_back(++ans);
			part[i]=seg[c].back();
			seg[c^1].push_back(seg[c].back());
			seg[c].pop_back();
		}
		cout << ans << '\n';
		for (int i=0; i<n; ++i)
			cout << part[i] << (i<n-1?' ':'\n');
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/