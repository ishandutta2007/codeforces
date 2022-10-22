#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k, a[200000];

bool ok(int x) {
	int cnt=0;
	int last=-5;
	for (int i=0; i<n; ++i) {
		if (i>last+1&&a[i]<=x) {
			last=i;
			cnt++;
		}
	}
	if (2*cnt-1>=k)
		return 1;
	cnt=0, last=-5;
	for (int i=1; i<n-1; ++i) {
		if (i>last+1&&a[i]<=x) {
			last=i;
			cnt++;
		}
	}
	if (2*cnt+1>=k)
		return 1;
	cnt=0, last=-5;
	for (int i=0; i<n-1; ++i) {
		if (i>last+1&&a[i]<=x) {
			last=i;
			cnt++;
		}
	}
	if (2*cnt>=k)
		return 1;
	cnt=0, last=-5;
	for (int i=1; i<n; ++i) {
		if (i>last+1&&a[i]<=x) {
			last=i;
			cnt++;
		}
	}
	if (2*cnt>=k)
		return 1;
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	int l=1, r=1e9;
	while(l<r) {
		int m=(l+r)/2;
		if (ok(m))
			r=m;
		else
			l=m+1;
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