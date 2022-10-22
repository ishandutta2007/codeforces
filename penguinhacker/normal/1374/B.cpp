#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int t, n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while(t--) {
		cin >> n;
		int ans=0;
		while(n>1) {
			if (n%3!=0) {
				ans=-1;
				break;
			}
			if (n%2==0) {
				++ans;
				n/=6;
			}
			else {
				ans+=2;
				n/=3;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/