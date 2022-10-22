#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, num, a[200000];

struct comp {
	bool operator()(pair<int, int> a, pair<int, int> b) const {
		int x=a.second-a.first;
		int y=b.second-b.first;
		return x==y?a.first<b.first:x>y;
	}
};

set<pair<int, int>, comp> q;

void solve() {
	cin >> n;
	num=0;
	q.insert({0, n-1});
	while (!q.empty()) {
		int l=q.begin()->first, r=q.begin()->second;
		q.erase(q.begin());
		if (l>r)
			break;
		if (l==r) {
			a[l]=++num;
			continue;
		}
		if ((r-l+1)&1) { //odd
			int mid=(l+r)/2;
			a[mid]=++num;
			q.insert({l, mid-1});
			q.insert({mid+1, r});
		}
		else {
			int mid=(l+r-1)/2;
			a[mid]=++num;
			q.insert({mid+1, r});
			q.insert({l, mid-1});
		}
	}
	q.clear();
	for (int i=0; i<n; ++i)
		cout << a[i] << (i<n-1?' ':'\n');
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

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/