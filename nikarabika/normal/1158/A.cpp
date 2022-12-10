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

const int maxn = 1e5 + 10;
int a[maxn],
	b[maxn],
	n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int j = 0; j < m; j++)
		cin >> b[j];
	sort(a, a + n);
	sort(b, b + m);
	if (b[0] < a[n - 1])
		return cout << -1 << endl, 0;
	LL ans = 0;
	for (int i = 0; i < n; i++)
		ans += 1LL * m * a[i];
	for (int i = 0; i < m; i++)
		ans += b[i] - a[n - 1];
	if (b[0] > a[n - 1])
		ans += a[n - 1] - a[n - 2];
	cout << ans << endl;
	return 0;
}