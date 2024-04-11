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
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		ll ans=0;
		for (int i=0; i<n; ++i) {
			cin >> a[i];
			ans+=a[i];
			a[i]-=n-i-1;
		}
		sort(a.rbegin(), a.rend());
		for (int i=0; i<k; ++i)
			ans-=a[i];
		ans-=(ll)k*(k-1)/2;
		cout << ans << "\n";
	}
	return 0;
}