#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int a, b, c, d, cnt[1000002];
ll suff[1000002], ans=0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b >> c >> d;
	for (int i=a+b; i<=b+c; ++i) {
		cnt[i]=1+min({b-a, c-b, i-a-b, b+c-i});
	}
	for (int i=b+c; ~i; --i)
		suff[i]=suff[i+1]+cnt[i+1];
	for (int i=c; i<=d; ++i)
		ans+=suff[i];
	cout << ans << '\n';
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/