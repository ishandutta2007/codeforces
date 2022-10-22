#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a, b, k, c[200000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> a >> b >> k;
	for (int i=0, h; i<n; ++i) {
		cin >> h, h%=a+b;
		if (h==0) h=a+b;
		c[i]=(h+a-1)/a-1;
	}
	sort(c, c+n);
	int ans=0;
	for (int i=0; i<n; ++i) {
		if (c[i]<=k) {
			++ans;
			k-=c[i];
		}
		else break;
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