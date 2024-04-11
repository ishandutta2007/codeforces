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
		int n, a, b;
		string s;
		cin >> n >> a >> b >> s;
		if (b>=0) {
			cout << n*(a+b) << "\n";
			continue;
		}
		int ans=n*a;
		int block=0;
		for (int i=0; i<n; ++i) {
			++block;
			while(i+1<n&&s[i]==s[i+1])
				++i;
		}
		ans+=(block/2+1)*b;
		cout << ans << "\n";
	}
	return 0;
}