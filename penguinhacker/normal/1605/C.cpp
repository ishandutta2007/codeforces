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
		int ans=1e9;
		for (int i=0; i+1<n; ++i) {
			if (s[i]=='a'&&s[i+1]=='a')
				ans=2;
			if (i+2<n&&s[i]=='a'&&s[i+2]=='a')
				ans=min(ans, 3);
			if (i+3<n&&s[i]=='a'&&s[i+3]=='a'&&s[i+1]^s[i+2])
				ans=min(ans, 4);
			if (i+6<n&&s[i]=='a'&&s[i+3]=='a'&&s[i+6]=='a'&&s[i+1]^s[i+4])
				ans=min(ans, 7);
		}
		cout << (ans==1e9?-1:ans) << "\n";
	}
	return 0;
}