#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[100000], ans=0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int j=30; j>0; --j) {
		int sum=0, best=0;
		for (int i=0; i<n; ++i) {
			if (a[i]>j)
				a[i]=-999999999;
			sum=max(sum+a[i], a[i]);
			best=max(best, sum);
		}
		ans=max(best-j, ans);
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