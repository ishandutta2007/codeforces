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
	const LL Mod = 998244353 ;
	int n;
	cin >> n;
	LL a[n],
	b[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	for (LL i = 0; i < n; i++)
		a[i] *= (i + 1) * (n - i);
	sort(a, a + n);
	sort(b, b + n);
	LL ans =0;
	for (int i = 0; i < n; i++) {
		a[i] %= Mod;
		ans = (ans + a[i] * b[n - 1 - i]) % Mod;
	}
	cout << ans << endl;
	return 0;
}