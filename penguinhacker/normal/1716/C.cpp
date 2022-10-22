#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, a[2][mxN], b[2][mxN], c[2][mxN];

void solve() {
	cin >> n;
	for (int i=0; i<2; ++i) {
		for (int j=0; j<n; ++j) {
			cin >> a[i][j];
			a[i][j]+=a[i][j]>0;
			b[i][j]=a[i][j]+j;
			c[i][j]=a[i][j]-j;
		}
		for (int j=n-2; ~j; --j) {
			b[i][j]=max(b[i][j], b[i][j+1]);
			c[i][j]=max(c[i][j], c[i][j+1]);
		}
	}
	int ans=2e9, cur=0;
	for (int i=0; i<n; ++i) {
		int x=cur;
		x=max(x, c[i%2][i]+2*n-1-i);
		x=max(x, b[(i%2==0)][i]-i);
		ans=min(ans, x);
		cur=max(cur, a[0][i]+2*(n-i-1)+(i%2==0));
		cur=max(cur, a[1][i]+2*(n-i-1)+(i%2));
		//cout << cur << endl;
		//cout << i << " " << ans << endl;
	}
	cout << min(ans, cur) << "\n";
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