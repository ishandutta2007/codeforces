#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[20000], ans=-1e9;

void solve(int step) {
	if (n/step<3)
		return;
	for (int i=0; i<step; ++i) {
		int cnt=0;
		for (int j=i; j<n; j+=step)
			cnt+=a[j];
		ans=max(ans, cnt);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=1; i*i<=n; ++i) {
		if (n%i)
			continue;
		solve(i);
		solve(n/i);
	}
	cout << ans;
	return 0;
}