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
		if ((s.back()-'0')%2==0) {
			cout << "0\n";
			continue;
		}
		if ((s[0]-'0')%2==0) {
			cout << "1\n";
			continue;
		}
		int ans=-1;
		for (char c : s)
			if ((c-'0')%2==0)
				ans=2;
		cout << ans << "\n";
	}
	return 0;
}