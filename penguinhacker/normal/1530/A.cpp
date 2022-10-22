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
		int ans=0;
		while(n) {
			ans=max(ans, n%10);
			n/=10;
		}
		cout << ans << "\n";
	}
	return 0;
}