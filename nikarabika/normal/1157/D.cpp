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

LL getmx(LL st, LL len) {
	if (st == 0) return 0;
	if (len > 30)
		return 1e18;
	return st * (1LL << len) - st;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	LL n, k;
	cin >> n >> k;
	if (k * (k + 1) / 2 > n)
		return cout << "NO" << endl, 0;
	pll seg(1, 1e9 + 10);
	vector<int> vec;
	for (int i = 0; i < k; i++) {
		LL lo = seg.L,
		   hi = seg.R + 1;
		while (hi - lo > 1) {
			LL mid = (lo + hi) >> 1;
			LL remin = (k - i) * (mid + mid + (k - i - 1)) / 2;
			if (remin > n)
				hi = mid;
			else
				lo = mid;
		}
		if (getmx(lo, k - i) < n)
			return cout << "NO" << endl, 0;
		vec.PB(lo);
		n -= lo;
		seg = pll(lo + 1, lo * 2);
	}
	cout << "YES" << endl;
	for (auto x : vec)
		cout << x << ' ';
	cout << endl;
	return 0;
}