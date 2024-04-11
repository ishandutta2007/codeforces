#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n;
ll k, x, a[mxN], d[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k >> x;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	sort(a, a+n);
	for (int i=0; i+1<n; ++i)
		d[i]=max(0ll, (a[i+1]-a[i]-1)/x);
	sort(d, d+n-1);
	int ans=n;
	for (int i=0; i<n-1; ++i) {
		k-=d[i];
		if (k>=0)
			--ans;
		else
			break;
	}
	cout << ans;
	return 0;
}