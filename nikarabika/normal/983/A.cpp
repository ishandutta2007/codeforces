//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

LL __gcdll(LL x, LL y) {
	return y == 0 ? x : __gcdll(y, x % y);
}	

LL zarb(LL x, LL y, LL md) {
	LL res = 0,
	   tmp = x % md;
	while (y) {
		if (y & 1) {
			res += tmp;
			if (res >= md)
				res -= md;
		}
		y >>= 1;
		tmp <<= 1;
		if (tmp >= md)
			tmp -= md;
	}
	return res;
}

void solve() {
	LL p, q, b;
	cin >> p >> q >> b;
	LL d = __gcdll(p, q);
	p /= d;
	q /= d;
	for (int i = 0; i < 7; i++) {
		b = zarb(b, b, q);
		if (b == 0) {
			cout << "Finite\n";
			return;
		}
	}
	cout << "Infinite\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	while (q--)
		solve();
	return 0;
}