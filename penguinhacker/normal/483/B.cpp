#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
const int MOD=1e9+7;

ll cnt1, cnt2, x, y;

bool pos(ll k) {
	if (x==y)
		return (k/x*(x-1)+k%x>=cnt1+cnt2?1:0);
	ll both=k-(k/x+k/y-k/(x*y));
	ll a=k-k/x-both;
	ll b=k-k/y-both;
	a-=cnt1;
	b-=cnt2;
	both+=min(0ll,a)+min(0ll,b);
	return (both>=0?1:0);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> cnt1 >> cnt2 >> x >> y;
	ll lo=1, hi=1e10;
	while (lo<hi) {
		ll mid=(lo+hi)/2;
		if (pos(mid))
			hi=mid;
		else
			lo=mid+1;
	}
	cout << lo;
	return 0;
}