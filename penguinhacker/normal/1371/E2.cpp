#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, p, a[100000];

int get(int x) {
	bool seen=0;
	for (int i=0, j=0; i<n; ++i) {
		while(j<n&&a[j]<=x+i)
			++j;
		int k=j-i;
		if (k==0)
			return 0;
		if (k>=p)
			seen=1;
	}
	return seen?2:1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> p;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	sort(a, a+n);
	int l=0, r=1e9;
	while(l<r) {
		int mid=(l+r)/2;
		int x=get(mid);
		if (x==0) l=mid+1;
		else r=mid;
	}
	if (get(l)!=1) {
		cout << 0;
		return 0;
	}
	int lb=l;
	l=0, r=1e9;
	while(l<r) {
		int mid=(l+r+1)/2;
		int x=get(mid);
		if (x<=1) l=mid;
		else r=mid-1;
	}
	int rb=l;
	//cout << lb << ' ' << rb;
	assert(lb<=rb&&rb-lb+1<=100000);
	vector<int> ans(rb-lb+1);
	iota(ans.begin(), ans.end(), lb);
	cout << rb-lb+1 << "\n";
	for (int i: ans)
		cout << i << " ";
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/