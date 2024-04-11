#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, a[mxN];
vector<int> x, y;

bool solve(int l, int r) {
	if (l==r)
		return 0;
	int mid=(l+r)/2;
	if (solve(l, mid)||solve(mid+1, r))
		return 1;
	x.clear();
	y.clear();
	for (int i=mid; i>=l; --i)
		x.push_back(a[i]);
	for (int i=mid+1; i<=r; ++i)
		y.push_back(a[i]);
	for (int rep=0; rep<2; ++rep) {
		int mx=INT_MIN;
		ll p1=0, p2=0, best=0;
		for (int i=0, j=0; i<x.size(); ++i) {
			mx=max(mx, x[i]);
			p1+=x[i];
			while(j<y.size()&&y[j]<=mx) {
				p2+=y[j];
				best=max(best, p2);
				++j;
			}
			if (mx<p1+best) {
				//cout << rep << " " << i << " " << j << " " << mx << endl;
				return 1;
			}
		}
		swap(x, y);
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		for (int i=0; i<n; ++i)
			cin >> a[i];
		cout << (solve(0, n-1)?"NO":"YES") << "\n";
	}
	return 0;
}