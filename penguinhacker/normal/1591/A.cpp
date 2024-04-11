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
		vector<int> a(n);
		for (int i=0; i<n; ++i)
			cin >> a[i];
		int ans=1;
		for (int i=0; i<n; ++i) {
			ans+=a[i];
			if (i&&!a[i]&&!a[i-1]) {
				ans=-1;
				break;
			}
			ans+=(i&&a[i]&&a[i-1]?4:0);
		}
		cout << ans << "\n";
	}
	return 0;
}