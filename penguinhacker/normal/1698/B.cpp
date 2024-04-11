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
		for (int& i : a)
			cin >> i;
		if (k==1) {
			cout << (n-1)/2 << "\n";
			continue;
		}
		int ans=0;
		for (int i=1; i+1<n; ++i)
			ans+=a[i]>a[i-1]+a[i+1];
		cout << ans << "\n";
	}
	return 0;
}