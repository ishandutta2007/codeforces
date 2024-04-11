#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, k, a[mxN], mx;
vector<int> changes[mxN+1];

void solve() {
	cin >> n >> k;
	mx=0;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		changes[a[i]/k].push_back(i);
		mx=max(mx, a[i]/k);
	}
	int ans=69696969;
	for (int i=0; i<=a[0]; ++i) {
		ans=min(ans, mx-i);
		if (i==a[0])
			break;
		for (int j : changes[i]) {
			int x=a[j]/(i+1);
			int y=a[j]/x;
			changes[y].push_back(j);
			mx=max(mx, y);
		}
		vector<int>().swap(changes[i]);
	}
	for (int i=0; i<=mxN; ++i)
		vector<int>().swap(changes[i]);
	cout << ans << "\n";
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