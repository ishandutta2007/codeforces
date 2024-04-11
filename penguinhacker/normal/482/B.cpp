#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, m, l[mxN], r[mxN], a[mxN], p[mxN+1], ans[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<m; ++i)
		cin >> l[i] >> r[i] >> a[i], --l[i], --r[i];
	for (int i=0; i<30; ++i) {
		for (int j=0; j<m; ++j)
			if (a[j]&1<<i)
				++p[l[j]], --p[r[j]+1];
		for (int j=1; j<n; ++j)
			p[j]+=p[j-1];
		for (int j=0; j<n; ++j) {
			p[j]=p[j]>0;
			if (p[j])
				ans[j]|=1<<i;
		}
		for (int j=1; j<n; ++j)
			p[j]+=p[j-1];
		for (int j=0; j<m; ++j)
			if (!(a[j]&1<<i)&&(p[r[j]]-(l[j]?p[l[j]-1]:0))==r[j]-l[j]+1) {
				cout << "NO";
				return 0;
			}
		memset(p, 0, 4*n);
	}
	cout << "YES\n";
	for (int i=0; i<n; ++i)
		cout << ans[i] << " ";
	return 0;
}