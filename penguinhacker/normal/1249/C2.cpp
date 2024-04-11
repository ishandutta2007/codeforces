#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

ll n, ans, pow3[39], pref[39];

void solve() {
	cin >> n, ans=0;
	while(n>0) {
		int k=0;
		for (int i=0; i<=38; ++i) {
			if (pref[i]>=n) {
				n-=pow3[i];
				ans+=pow3[i];
				break;
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	pow3[0]=pref[0]=1;
	for (int i=1; i<=38; ++i)
		pow3[i]=pow3[i-1]*3, pref[i]=pref[i-1]+pow3[i];

	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/