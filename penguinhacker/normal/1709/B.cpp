#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, m, a[mxN];
ll p1[mxN+1], p2[mxN+1];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=1; i<n; ++i) {
		p1[i+1]=p1[i]+max(0, a[i-1]-a[i]);
		p2[i+1]=p2[i]+max(0, a[i]-a[i-1]);
	}
	while(m--) {
		int l, r;
		cin >> l >> r;
		if (l==r)
			cout << "0\n";
		else if (l<r)
			cout << p1[r]-p1[l] << "\n";
		else
			cout << p2[l]-p2[r] << "\n";
	}
	return 0;
}