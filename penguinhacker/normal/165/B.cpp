#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k;

bool ok(int x) {
	ll a=0;
	while(x) {
		a+=x;
		x/=k;
	}
	return a>=n;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	int l=1, r=n;
	while(l<r) {
		int mid=(l+r)/2;
		if (ok(mid))
			r=mid;
		else
			l=mid+1;
	}
	cout << l;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/