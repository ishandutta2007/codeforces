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
		int n, l, r;
		cin >> n >> l >> r;
		vector<int> a(n);
		for (int& i : a)
			cin >> i;
		ll ans=0;
		sort(a.begin(), a.end());
		for (int i : a) {
			ans+=upper_bound(a.begin(), a.end(), r-i)-lower_bound(a.begin(), a.end(), l-i);
			ans-=l<=2*i&&2*i<=r;
		}
		cout << ans/2 << "\n";
	}
	return 0;
}