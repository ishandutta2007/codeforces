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

const LL Mod = 998244353;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	LL n;
	cin >> n;
	LL ans = 1;
	for (LL i = 2; i <= n; i++)
		ans = (ans * i) % Mod;
	ans = (ans * n) % Mod;
	ans -= n - 1;
	LL tmp = 1;
	for (LL i = n; i > 1; i--) {
		tmp = (tmp * i) % Mod;
		ans -= tmp - 1;
		ans %= Mod;
	}
	ans = (ans + Mod) % Mod;
	cout << ans << endl;
	return 0;
}