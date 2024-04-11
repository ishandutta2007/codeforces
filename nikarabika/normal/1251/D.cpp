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

const int maxn = 2e5 + 10;
LL l[maxn],
   r[maxn],
   n, s;

bool check(LL val) {
	LL rem = s;
	int bigger, less;
	bigger = less = 0;
	for (int i = 0; i < n; i++)
		if (l[i] > val) {
			rem -= l[i];
			bigger++;
		}
	for (int i = 0; i < n; i++)
		if (r[i] < val) {
			rem -= l[i];
			less++;
		}
	int exp_bigger = n / 2 + 1;
	int exp_less = n / 2;
	if (less > exp_less)
		return false;
	vector<pll> vec;
	for (int i = 0; i < n; i++)
		if (l[i] <= val and r[i] >= val)
			vec.PB(MP(l[i], r[i]));
	sort(all(vec));
	int last = sz(vec);
	for (int i = 0; i < exp_bigger - bigger; i++) {
		int idx = sz(vec) - i - 1;
		rem -= val;
		last = idx;
	}
	for (int i = 0; i < last; i++)
		rem -= vec[i].L;
	return rem >= 0;
}

int solve() {
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> l[i] >> r[i];
	LL lo = 0,
	   hi = 2e14 + 1;
	while (hi - lo > 1) {
		LL mid = (lo + hi) >> 1;
		if (check(mid))
			lo = mid;
		else
			hi = mid;
	}
	cout << lo << '\n';
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