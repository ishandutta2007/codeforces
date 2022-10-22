#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, a[300000][8], b[1<<8];

pair<int, int> chk(int x) {
	fill(b, b+(1<<m), -1);
	for (int i=0; i<n; ++i) {
		int curr=0;
		for (int j=0; j<m; ++j)
			if (a[i][j]>=x)
				curr^=(1<<j);
		b[curr]=i+1;
	}
	for (int i=0; i<(1<<m); ++i)
		for (int j=0; j<(1<<m); ++j)
			if ((i|j)==(1<<m)-1)
				if (b[i]!=-1&&b[j]!=-1)
					return {b[i], b[j]};
	return {-1, -1};
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cin >> a[i][j];
	int l=0, r=1e9;
	while(l<r) {
		int mid=(l+r+1)/2;
		pair<int, int> x=chk(mid);
		if (x==make_pair(-1, -1))
			r=mid-1;
		else
			l=mid;
	}
	pair<int, int> ans=chk(l);
	cout << ans.first << ' ' << ans.second;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/