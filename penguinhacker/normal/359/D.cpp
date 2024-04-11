#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=3e5;
int n, a[mxN], st[mxN][19], lg[mxN+1], best=-1;
vector<int> ans;

int qry(int l, int r) {
	int k=lg[r-l+1];
	return __gcd(st[l][k], st[r-(1<<k)+1][k]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i], st[i][0]=a[i];
	for (int j=1; 1<<j<=n; ++j)
		for (int i=0; i+(1<<j)-1<n; ++i)
			st[i][j]=__gcd(st[i][j-1], st[i+(1<<j-1)][j-1]);
	lg[1]=0;
	for (int i=2; i<=n; ++i)
		lg[i]=lg[i>>1]+1;
	for (int i=0; i<n; ++i) {
		int lb=0, rb=i;
		while(lb<rb) {
			int mid=(lb+rb)/2;
			if (qry(mid, i)==a[i])
				rb=mid;
			else
				lb=mid+1;
		}
		int l=lb;
		lb=i, rb=n-1;
		while(lb<rb) {
			int mid=(lb+rb+1)/2;
			if (qry(i, mid)==a[i])
				lb=mid;
			else
				rb=mid-1;
		}
		int r=lb;
		if (r-l>=best) {
			if (r-l>best) {
				best=r-l;
				ans.clear();
			}
			ans.push_back(l+1);
		}
	}
	ans.resize(unique(ans.begin(), ans.end())-ans.begin());
	cout << ans.size() << " " << best << "\n";
	for (int i : ans)
		cout << i << " ";
	return 0;
}