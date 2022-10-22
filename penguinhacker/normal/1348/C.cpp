#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k;
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		cin >> n >> k >> s;
		vector<string> ans(k);
		sort(s.begin(), s.end());
		for (int i=0; i<k; ++i)
			ans[i].push_back(s[i]);
		if (ans[0]!=ans[k-1]||n==k) {
			cout << ans[k-1] << '\n';
			continue;
		}
		if (s[k]==s[n-1]) {
			for (int i=k; i<n; i+=k)
				ans[0]+=s[i];
			cout << ans[0] << '\n';
		}
		else
			cout << ans[0] << s.substr(k, n-k) << '\n';
	}
	return 0;
}