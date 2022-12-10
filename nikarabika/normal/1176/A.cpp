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
	LL n, ans = 0;
	cin >> n;
	while (n != 1) {
		if (n % 2 == 0)
			n /= 2, ans++;
		else if (n % 3 == 0)
			n /= 3, n *= 2, ans++;
		else if (n % 5 == 0)
			n /= 5, n *= 4, ans++;
		else
			return cout << -1 << '\n', 0;
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}