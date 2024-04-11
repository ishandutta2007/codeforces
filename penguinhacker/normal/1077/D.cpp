#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k, c[200001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i=0, a; i<n; ++i)
		cin >> a, ++c[a];
	int l=1, r=n/k+2;
	while(l<r) {
		int mid=(l+r+1)/2;
		int cnt=0;
		for (int i=1; i<=200000; ++i)
			cnt+=c[i]/mid;
		if (cnt>=k) l=mid;
		else r=mid-1;
	}
	for (int cnt=0, i=1; i<=200000&&cnt<k; ) {
		if (c[i]<l) {
			++i;
			continue;
		}
		c[i]-=l;
		++cnt;
		cout << i << ' ';
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/