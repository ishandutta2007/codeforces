#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;
bool solve(string s, string t) {
	vector<int> a[2], b[2];
	for (int i=0; i<2*n; ++i)
		a[s[i]-'0'].push_back(i);
	for (int i=0; i<2*n; ++i)
		b[t[i]-'0'].push_back(i);
	for (int p : {0, 1}) {
		int k=min(a[p].size(), b[p].size());
		if (k>=n) {
			//cout << s << " " << t << " " << p << endl;
			a[p].resize(k), b[p].resize(k);
			a[p].insert(a[p].begin(), -1);
			b[p].insert(b[p].begin(), -1);
			a[p].push_back(2*n);
			b[p].push_back(2*n);
			assert(a[p].size()==k+2&&b[p].size()==k+2);
			string ans;
			for (int i=1; i<=k+1; ++i) {
				ans+=s.substr(a[p][i-1]+1, a[p][i]-a[p][i-1]-1);
				ans+=t.substr(b[p][i-1]+1, b[p][i]-b[p][i-1]-1);
				if (i<=k)
					ans.push_back('0'+p);
			}
			cout << ans << "\n";
			return 1;
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		string a, b, c;
		cin >> n >> a >> b >> c;
		solve(a, b)||solve(b, c)||solve(a, c);
	}
	return 0;
}