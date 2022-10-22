#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

ll n, k;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		for (int i=0; i<k-1; ++i) {
			ll temp=n;
			int mn=100, mx=-1;
			while(temp) {
				int x=temp%10;
				mn=min(x, mn);
				mx=max(x, mx);
				temp/=10;
			}
			if (mn==0)
				break;
			n+=mn*mx;
		}
		cout << n << '\n';
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/