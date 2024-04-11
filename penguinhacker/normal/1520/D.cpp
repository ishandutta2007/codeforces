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
		cin >> n;
		map<int, int> mp;
		ll ans=0;
		for (int i=0; i<n; ++i) {
			int a;
			cin >> a;
			ans+=mp[a-i]++;
		}
		cout << ans << "\n";
	}
	return 0;
}