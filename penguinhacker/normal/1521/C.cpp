#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int qry(int t, int i, int j, int x) {
	cout << "? " << t << " " << i << " " << j << " " << x << endl;
	int r;
	cin >> r;
	if (r==-1)
		exit(0);
	return r;
}

void solve() {
	int n;
	cin >> n;
	vector<int> tocheck, ans(n+1);
	if (n%2)
		tocheck.push_back(1);
	for (int i=1+n%2; i<=n; i+=2) {
		if (qry(2, i, i+1, 1)<=2) {
			tocheck.push_back(i);
			tocheck.push_back(i+1);
		}
	}
	int ind=-1;
	for (int i : tocheck) {
		if (qry(2, i, i==1?2:1, 1)==1) {
			ind=i;
			break;
		}
	}
	assert(ind^-1);
	ans[ind]=1;
	for (int i=1; i<=n; ++i)
		if (i^ind)
			ans[i]=qry(1, ind, i, n-1);
	cout << "!";
	for (int i=1; i<=n; ++i)
		cout << " " << ans[i];
	cout << endl;
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