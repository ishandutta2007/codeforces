#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		ll m, l, r;
		cin >> l >> r >> m;
		int R=r-l;
		for (int a=l; a<=r; ++a) {
			ll k=max(m-R, 1ll);
			if ((k+a-1)/a*a<=m+R) {
				cout << a << ' ';
				ll d=(k+a-1)/a*a-m;
				int b, c;
				if (d<0) {
					c=l;
					b=l-d;
				}
				else {
					b=l;
					c=d+l;
				}
				cout << b << ' ' << c << '\n';
				break;
			}
		}
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/