#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k, p, a[1000], b[2000];

bool ok(int x) {
	for (int i=0, j=0; i<n; ++i, ++j) {
		while(j<k&&a[i]-b[j]+abs(b[j]-p)>x)
			++j;
		if (j==k||abs(a[i]-b[j])+abs(b[j]-p)>x)
			return 0;
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k >> p;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=0; i<k; ++i)
		cin >> b[i];
	sort(a, a+n);
	sort(b, b+k);
	int l=0, r=2e9;
	while(l<r) {
		int mid=(0ll+l+r)/2;
		if (ok(mid))
			r=mid;
		else
			l=mid+1;
	}
	cout << l;
	return 0;
}