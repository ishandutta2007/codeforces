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
		vector<int> a(n+2);
		for (int i=1; i<=n; ++i)
			cin >> a[i];
		vector<int> inds(n);
		iota(inds.begin(), inds.end(), 1);
		sort(inds.begin(), inds.end(), [&](int x, int y) {return a[x]>a[y];});
		ll ans=0;
		for (int i=1; i<=n+1; ++i)
			ans+=abs(a[i]-a[i-1]);
		for (int i : inds) {
			if (a[i]>a[i-1]&&a[i]>a[i+1]) {
				ans-=a[i]-max(a[i-1], a[i+1]);
				a[i]=max(a[i-1], a[i+1]);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}