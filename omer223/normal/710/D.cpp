#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <queue>
#include <bitset>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll extgcd(ll a, ll b, ll& x, ll& y) { if (b == 0) { x = 1; y = 0; return a; } else { int g = extgcd(b, a%b, y, x); y -= a / b * x; return g; } }

ll myceil(ll a, ll b) {
	if (a < 0 ^ b < 0)
		return -abs(a) / abs(b);
	else
		return abs(a) / abs(b) + (abs(a)%abs(b) != 0);
}

ll myfloor(ll a, ll b) {
	if (a < 0 ^ b < 0)
		return -(abs(a) / abs(b) + (abs(a) % abs(b) != 0));
	else
		return abs(a) / abs(b);
}


int main() {
	fast;
	ll a1, d1, a2, d2, l, r;
	cin >> d1 >> a1 >> d2 >> a2 >> l >> r;
	if (a2 > a1) {
		swap(d1, d2);
		swap(a1, a2);
	}
	ll y0 = 0, x0 = 0;
	ll g = extgcd(-d1, d2, x0, y0);
	if ((a1 - a2) % g != 0 && a1 != a2)
		cout << 0 << '\n';
	else if (a1 == a2) {
		ll meet = a1, lcmm = (d1*d2)/gcd(d1,d2);
		ll n1 = myceil(l-meet,lcmm),n2=myfloor(r-meet,lcmm);
		ll n0 = myceil(max(a1,a2)-meet,lcmm);
		n1=max(n1,n0);
		cout<<max(0LL,n2-n1+1)<<'\n';
	}
	else {
		x0 *= ((a1 - a2) / g);
		y0 *= ((a1 - a2) / g);
		x0 %= (d2/gcd(d1,d2));
		ll meet = d1 * x0 + a1, lcmm = (d1*d2) / gcd(d1, d2);
		ll n1 = myceil(l - meet, lcmm), n2 = myfloor(r - meet, lcmm);
		ll n0 = myceil(max(a1,a2)-meet,lcmm);
		n1=max(n1,n0);
		cout<<max(0LL,n2-n1+1)<<'\n';
	}
	//cin >> a1;
	return 0;
}