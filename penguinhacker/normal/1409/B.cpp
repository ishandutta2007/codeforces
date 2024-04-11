#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

ll solve(ll a, ll b, ll x, ll y, ll n) {
	ll d=min(n, b-y);
	n-=d, b-=d;
	d=min(n, a-x);
	a-=d;
	return a*b;
}

ll n, x, y, a, b;

void test_case() {
	cin >> a >> b >> x >> y >> n;
	if (n>=a-x+b-y) {cout << x*y << "\n"; return;}

	//if (a<b) swap(a, b), swap(x, y);
	ll ans=min(solve(a, b, x, y, n), solve(b, a, y, x, n));
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t=1; cin >> t;
	while(t--) test_case();
	return 0;
}