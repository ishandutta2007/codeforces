#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, c, a[200000], b[200000];

void solve() {
	cin >> n >> c;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=0; i<n-1; ++i)
		cin >> b[i];
	int m=0;
	ll ans=1e18, cur=0;
	for (int i=0; i<n-1; ++i) {
		int x=m-c;
		ans=min(ans, cur+(-x+a[i]-1)/a[i]);
		m-=b[i];
		if (m>=0) {
			++cur;
			continue;
		}
		x=(-m+a[i]-1)/a[i];
		cur+=x+1, m+=x*a[i];
	}
	//cout << cur << "\n";
	m-=c;
	ans=min(ans, cur+(-m+a[n-1]-1)/a[n-1]);
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}