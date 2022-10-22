#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[200000], c[20];
ll ans=0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		for (int j=19; ~j; --j) {
			if (a[i]&(1<<j))
				++c[j];
		}
	}
	for (int i=0; i<n; ++i) {
		ll curr=0;
		for (int j=0; j<20; ++j) {
			if (c[j]) {
				curr+=(1<<j);
				--c[j];
			}
		}
		ans+=curr*curr;
	}
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/