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

LL pos[100];

LL sum(LL l, LL r) {
	return (r + l) * (r - l + 1) / 2;
}

LL getseqlen(LL n) {
	LL ans = 0;
	LL tmp, i;
	for (tmp = 1, i = 1; tmp * 10 <= n; tmp *= 10, i++) {
		ans += i * sum(n - (tmp * 10) + 2, n - (tmp - 1));
	}
	ans += sum(1, n - (tmp - 1)) * i;
	return ans;
}

LL getlen(LL n) {
	LL ans = 0;
	LL tmp, i;
	for (tmp = 1, i = 1; tmp * 10 <= n; tmp *= 10, i++) {
		ans += tmp * 9 * i;
	}
	ans += (n - tmp + 1) * i;
	return ans;
}

int solve() {
	LL k;
	cin >> k;
	LL lo = 0,
	   hi = 1e9;
	while (hi - lo > 1) {
		LL mid = (lo + hi) >> 1;
		if (getseqlen(mid) < k)
			lo = mid;
		else
			hi = mid;
	}
	k -= getseqlen(lo);
	// search from 1..hi
	lo = 0;
	while (hi - lo > 1) {
		LL mid = (lo + hi) >> 1;
		if (getlen(mid) < k)
			lo = mid;
		else
			hi = mid;
	}
	k -= getlen(lo);
	vector<int> vec;
	while (hi) {
		vec.PB(hi % 10);
		hi /= 10;
	}
	cout << vec[sz(vec) - k] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}