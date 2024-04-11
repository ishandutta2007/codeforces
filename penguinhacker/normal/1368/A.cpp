#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int t, n, a, b;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while(t--) {
		cin >> a >> b >> n;
		int cnt=0;
		while(1) {
			if (a<b)
				swap(a, b);
			if (a>n)
				break;
			b+=a;
			++cnt;
		}
		cout << cnt << '\n';
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/