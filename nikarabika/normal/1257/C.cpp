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

int solve() {
	int n;
	cin >> n;
	int last[n];
	fill(last, last + n, -1);
	int ans = 1e9;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		x--;
		if (~last[x])
			smin(ans, i - last[x]);
		last[x] = i;
	}
	if (ans == 1e9)
		cout << -1 << '\n';
	else
		cout << ans + 1 << '\n';
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