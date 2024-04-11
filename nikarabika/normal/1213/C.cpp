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
	LL n, m;
	cin >> n >> m;
	int a[11] = {0};
	LL sum = 0;
	for (int i = 1; i <= 10; i++)
		a[i] = (a[i - 1] + m) % 10, sum += a[i];
	LL cnt = n / m;
	LL ans = (cnt / 10) * sum;
	for (int i = 0; i < cnt % 10; i++)
		ans += a[i + 1];
	cout << ans << '\n';
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