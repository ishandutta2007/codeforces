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

void solve() {
	int c, m, x;
	cin >> c >> m >> x;
	int lo = 0, hi = 1e9;
	while (hi - lo > 1) {
		int mid = (lo + hi) >> 1;
		if (c >= mid and m >= mid and (c - mid) + (m - mid) + x >= mid)
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