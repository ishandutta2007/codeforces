#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	ll ans=0;
	ll a, b;
	for (int i=0; i<n; ++i) {
		cin >> a >> b;
		ll x=a*b/__gcd(a, b);
		if (i==0)
			ans=x;
		else
			ans=__gcd(ans, x);
	}
	if (__gcd(a, ans)>1) {
		ans = __gcd(a, ans);
	} else if (__gcd(b, ans)>1) {
		ans = __gcd(b, ans);
	}
	if (ans==1) {
		cout << -1;
		return 0;
	}
	for (int i=2; i*i<=ans; ++i)
		if (ans%i==0) {
			cout << i;
			return 0;
		}
	cout << ans;
	return 0;
}