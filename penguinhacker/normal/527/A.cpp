#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll a, b;
	cin >> a >> b;
	if (a<b)
		swap(a, b);
	ll ans=0;
	while(b) {
		ans+=a/b;
		a%=b;
		swap(a, b);
	}
	cout << ans;
	return 0;
}