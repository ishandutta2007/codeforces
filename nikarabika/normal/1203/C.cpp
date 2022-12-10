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

LL gcd(LL x, LL y) {
	return (y == 0) ? x : gcd(y, x % y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	LL n, d = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		LL x;
		cin >> x;
		d = gcd(x, d);
	}
	int ans = 0;
	for (LL i = 1; i * i <= d; i++)
		if (d % i == 0)
			ans += 1 + (i * i != d);
	cout << ans << endl;
	return 0;
}