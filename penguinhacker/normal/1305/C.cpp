#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n, m, a[200000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	ll ans = 1;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
	}
	if (n > m) {
		cout << 0 << '\n';
		return 0;
	}
	for (int i=0; i<n; ++i)
		for (int j=i+1; j<n; ++j)
			ans = ans*(abs(a[i]-a[j]))%m;
		
	cout << ans;
	return 0;
}