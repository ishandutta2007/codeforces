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
		int n; string s;
		cin >> n >> s;
		bool seen=0;
		ar<int, 2> cnt={0, 0};
		for (int i=0; i<n; ++i) {
			if (s[i]=='0') ++cnt[0];
			else break;
		}
		for (int i=n-1; i>=0; --i) {
			if (s[i]=='1') ++cnt[1];
			else break;
		}
		for (int i=0; i<n-1; ++i)
			if (s[i]=='1'&&s[i+1]=='0')
				seen=1;
		string part1(cnt[0], '0'), part2(cnt[1], '1');
		string ans=part1+part2;
		if (seen)
			ans="0"+ans;
		cout << ans << '\n';
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/