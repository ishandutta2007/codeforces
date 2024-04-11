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
		int n, ans=0;
		cin >> n;
		for (ll i=1; i<=n; i=10*i+1)
			for (int j=1; j<=9; ++j)
				ans+=i*j<=n;
		cout << ans << "\n";
	}
	return 0;
}