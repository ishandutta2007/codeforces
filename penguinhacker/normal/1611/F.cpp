#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, s, a[mxN], lg[mxN+1];
ll p[mxN+1], st[mxN+1][18];

void solve() {
	cin >> n >> s;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		p[i+1]=p[i]+a[i];
	}
	if (*max_element(a, a+n)+s<0) {
		cout << "-1\n";
		return;
	}
	for (int i=1; i<=n; ++i)
		st[i][0]=p[i];
	for (int j=1; (1<<j)<=n; ++j)
		for (int i=1; i+(1<<j)-1<=n; ++i)
			st[i][j]=min(st[i][j-1], st[i+(1<<j-1)][j-1]);
	ar<int, 2> ans={0, -1};
	for (int i=0; i<n; ++i) {
		if (a[i]+s<0)
			continue;
		int lb=i, rb=n-1;
		while(lb<rb) {
			int mid=(lb+rb+1)/2;
			// query range [i+1, mid+1]
			int k=lg[mid-i+1];
			ll mn=min(st[i+1][k], st[mid+1-(1<<k)+1][k]);
			if (mn-p[i]+s<0)
				rb=mid-1;
			else
				lb=mid;
		}
		if (lb-i>ans[1]-ans[0])
			ans={i, lb};
	}
	//cout << st[2][1] << endl;
	cout << ans[0]+1 << " " << ans[1]+1 << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i=2; i<=mxN; ++i)
		lg[i]=lg[i/2]+1;
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}