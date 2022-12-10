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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	pll a[n];
	LL ans = 0;
	for (int i = 0; i < n; i++)
		cin >> a[i].L, a[i].R = i;
	sort(a, a + n, greater<pll>());
	for (int i = 0; i < n; i++)
		ans += a[i].L * i+ 1;
	cout << ans << endl;
	for (int i = 0; i < n; i++)
		cout << a[i].R + 1 << ' ';
	cout << endl;
	return 0;
}