#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k;
vector<ll> a;

bool ok(ll x) {
	ll need=0;
	for (int i : a) need+=max(0ll, x-i);
	return need<=k;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	a.resize(n);
	for (ll &i : a) cin >> i;
	sort(a.begin(), a.end());
	a=vector<ll>(a.begin()+n/2, a.end());
	ll l=0, r=3e9;
	while(l<r) {
		ll mid=(l+r+1)/2;
		if (ok(mid)) l=mid;
		else r=mid-1;
	}
	cout << l;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/