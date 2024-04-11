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
		int n, d;
		cin >> n >> d;
		vector<int> a(n);
		for (int& i : a)
			cin >> i;
		int ans=a[0];
		for (int i=1; i<n; ++i) {
			if (d>=i*a[i]) {
				d-=i*a[i];
				ans+=a[i];
			} else {
				ans+=d/i;
				break;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}