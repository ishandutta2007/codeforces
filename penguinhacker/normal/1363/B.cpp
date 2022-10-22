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
		string s; cin >> s;
		int c1=0, c2, ans=1e9;
		c2=count(s.begin(), s.end(), '1');
		for (char c: s) {
			if (c=='0') ++c1;
			else --c2;
			ans=min(ans, min(c1+c2, (int)s.size()-c1-c2));
		}
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