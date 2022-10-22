#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, m, k, t, a[mxN], p[mxN+1];
ar<int, 3> trap[mxN];

bool pos(int x) {
	memset(p, 0, 4*n);
	for (int i=0; i<k; ++i)
		if (trap[i][2]>x)
			++p[trap[i][0]-1], --p[trap[i][1]];
	int need=n+1;
	for (int i=0; i<n; ++i) {
		need+=2*(p[i]>0);
		p[i+1]+=p[i];
	}
	return need<=t;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n >> k >> t;
	for (int i=0; i<m; ++i)
		cin >> a[i];
	sort(a, a+m, greater<int>());
	for (int i=0; i<k; ++i)
		cin >> trap[i][0] >> trap[i][1] >> trap[i][2];
	int l=0, r=m;
	while(l<r) {
		int mid=(l+r+1)/2;
		if (pos(mid?a[mid-1]:1e9))
			l=mid;
		else
			r=mid-1;
	}
	cout << l;
	return 0;
}