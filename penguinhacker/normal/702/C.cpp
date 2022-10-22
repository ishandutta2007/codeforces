#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=100000;
int n, m, a[mxN], b[mxN], d[mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i) cin >> a[i], d[i]=INT_MAX;
	for (int i=0; i<m; ++i) cin >> b[i];
	for (int p1=0, p2=0; p2<m; ++p2) {
		while(p1<n&&a[p1]<=b[p2]) {
			d[p1]=min(d[p1], b[p2]-a[p1]);
			++p1;
		}
	}
	for (int p1=n-1, p2=m-1; p2>=0; --p2) {
		while(p1>=0&&a[p1]>=b[p2]) {
			d[p1]=min(d[p1], a[p1]-b[p2]);
			--p1;
		}
	}
	int ans=0;
	for (int i=0; i<n; ++i) ans=max(ans, d[i]);
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/