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
		ll ans=accumulate(a.begin(), a.end()-1, 0ll);
		int i=0;
		for (; i<n&&!a[i]; ++i);
		for (; i<n-1; ++i)
			ans+=!a[i];
		cout << ans << "\n";
	}
	return 0;
}