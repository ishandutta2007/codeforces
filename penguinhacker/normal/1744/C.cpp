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
		char st;
		string s;
		cin >> n >> st >> s;
		if (st=='g') {
			cout << "0\n";
			continue;
		}
		s+=s;
		int cur=-69696969;
		int ans=0;
		for (int i=2*n-1; ~i; --i) {
			if (s[i]=='g') {
				cur=0;
				continue;
			}
			++cur;
			if (s[i]==st)
				ans=max(ans, cur);
		}
		cout << ans << "\n";
	}
	return 0;
}