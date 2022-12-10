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
	int b, w;
	cin >> b >> w;
	pii start(5, 5);
	if (b < w) {
		swap(b, w);
		start.L++;
	}
	if (b > 3 * w + 1) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	vector<int> yts;
	for (int i = 0; i < w; i++) {
		yts.PB(start.R + 2 * i);
		cout << start.L << ' ' << yts.back() << '\n';
	}
	for (int i = 0; i < w and b; i++, b--)
		cout << start.L << ' ' << yts[i] - 1 << '\n';
	for (int i = 0; i < w and b; i++, b--)
		cout << start.L - 1 << ' ' << yts[i] << '\n';
	for (int i = 0; i < w and b; i++, b--)
		cout << start.L + 1 << ' ' << yts[i] << '\n';
	if (b)
		cout << start.L << ' ' << yts.back() + 1 << '\n';
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