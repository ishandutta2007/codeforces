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
		ll ans=n;
		for (int i=1; i<n; ++i)
			if (s[i]!=s[i-1])
				ans+=i;
		cout << ans << "\n";
	}
	return 0;
}