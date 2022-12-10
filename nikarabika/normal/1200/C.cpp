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

LL gcdll(LL x, LL y) {
	return y == 0 ? x : gcdll(y, x % y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	LL n, m, q;
	cin >> n >> m >> q;
	LL d = gcdll(n, m);
	LL len1 = n / d,
	   len2 = m / d;
	while (q--) {
		LL fi, se, th, fo;
		cin >> fi >> se >> th >> fo;
		se--, fo--;
		LL p1, p2;
		p1 = (fi == 1) ? se / len1 : se / len2;
		p2 = (th == 1) ? fo / len1 : fo / len2;
		cout << (p1 ^ p2 ? "NO\n" : "YES\n");
	}
	return 0;
}