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
		string s;
		cin >> s;
		int x=0;
		ll ans=s.size();
		vector<bool> b(s.size()+1);
		for (int i=0; i<s.size(); ++i) {
			x+=(s[i]=='+'?-1:+1);
			if (x>0&&!b[x]) {
				b[x]=1;
				ans+=i+1;
			}
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