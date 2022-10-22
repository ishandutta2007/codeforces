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
		vector<ar<int, 2>> a(n);
		for (int i=0; i<n; ++i)
			cin >> a[i][0], a[i][1]=i;
		vector<int> ans(n);
		ll x=0;
		sort(a.rbegin(), a.rend());
		for (int i=0; i<n; ++i) {
			x+=2ll*(i/2+1)*a[i][0];
			ans[a[i][1]]=(i/2+1)*(i%2?-1:1);
		}
		cout << x << "\n0";
		for (int i : ans)
			cout << " " << i;
		cout << "\n";
	}
	return 0;
}