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
	int p, b, f;
	int h, c;
	cin >> b >> p >> f
		>> h >> c;
	int ans = 0;
	for (int i = 0; i <= p; i++)
		if (i * 2 <= b)
			smax(ans, i * h + min((b - 2 * i) / 2, f) * c);
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