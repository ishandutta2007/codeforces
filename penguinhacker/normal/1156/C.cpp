#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k, a[200000];

bool ok(int x) {
	vector<int> v1, v2;
	for (int i=0; i<x; ++i)
		v1.push_back(a[i]);
	for (int i=n-x; i<n; ++i)
		v2.push_back(a[i]);
	for (int i=0; i<x; ++i)
		if (v2[i]-v1[i]<k)
			return 0;
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	sort(a, a+n);
	int l=0, r=n/2;
	while(l<r) {
		int mid=(l+r+1)/2;
		if (ok(mid))
			l=mid;
		else
			r=mid-1;
	}
	cout << l;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/