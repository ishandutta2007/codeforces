#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int t, a, b;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while(t--) {
		cin >> a >> b;
		if (a<b)
			swap(a, b);
		int ans=min(b, a-b);
		a-=2*ans, b-=ans;
		ans+=b/3*2;
		if (b%3==2)
			++ans;
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