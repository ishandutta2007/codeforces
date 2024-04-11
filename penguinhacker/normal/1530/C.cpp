#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, a[mxN], b[mxN], p1[mxN+1], p2[mxN+1];

void solve() {
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=0; i<n; ++i)
		cin >> b[i];
	sort(a, a+n);
	sort(b, b+n);
	for (int i=0; i<n; ++i) {
		p1[i+1]=p1[i]+a[i];
		p2[i+1]=p2[i]+b[i];
	}
	int lb=0, rb=3*n;
	while(lb<rb) {
		int mid=(lb+rb)/2;
		int k=(n+mid)/4;
		int me=100*mid+p1[n]-p1[k];
		int him=p2[n]-p2[max(0, k-mid)];
		if (me>=him)
			rb=mid;
		else
			lb=mid+1;
	}
	cout << lb << "\n";
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