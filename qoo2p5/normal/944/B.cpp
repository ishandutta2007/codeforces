#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9 + 1e6 + 123;
const ll LINF = (ll) 1e18 + 1e9 + 123;
const ll MOD = (ll) 1e9 + 7;

#define rep(i, s, t) for (auto i = (s); i < (t); ++(i))
#define per(i, s, t) for (auto i = (s); i >= (t); --(i))
#define sz(x) ((int)(x).size())
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

template<typename A, typename B> bool mini(A &x, const B &y) {
	if (y < x) {
		x = y;
		return 1;
	}
	return 0;
}

template<typename A, typename B> bool maxi(A &x, const B &y) {
	if (y > x) {
		x = y;
		return 1;
	}
	return 0;
}

ll power(ll x, ll y, ll mod=MOD) {
	if (y == 0) {
		return 1;
	}
	if (y % 2 == 1) {
		return power(x, y - 1, mod) * x % MOD;
	} else {
		ll t = power(x, y / 2, mod);
		return t * t % MOD;
	}
}

void add(ll &x, ll y) {
	x += y;
	if (x >= MOD) x -= MOD;
	if (x < 0) x += MOD;
}

ll mult(ll x, ll y) {
	return x * y % MOD;
}

void run();

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	run();
	return 0;
}

const int N = (int) 1e5 + 123;

int n;
int a[N];
int b[N];

void run() {
	cin >> n;
	rep(i, 0, n) cin >> a[i];
	int mi = *min_element(a, a + n);
	int ma = *max_element(a, a + n);
	rep(i, 0, n) a[i] -= mi;
	
	if (ma - mi == 2) {
		int x = 0, y = 0, z = 0;
		rep(i, 0, n) {
			assert(0 <= a[i] && a[i] <= 2);
			if (a[i] == 0) x++;
			else if (a[i] == 1) y++;
			else z++;
		}
		
		int ans = INF;
		int best_x = -1, best_y = -1, best_z = -1;
		
		rep(yy, 0, n + 1) {
			if ((y + 2 * z - yy) % 2 != 0) continue;
			int zz = (y + 2 * z - yy) / 2;
			int xx = n - yy - zz;
			if (zz < 0 || xx < 0) continue;
			if (mini(ans, min(xx, x) + min(yy, y) + min(zz, z))) {
				best_x = xx;
				best_y = yy;
				best_z = zz;
			}
		}
		assert(best_y + best_z * 2 == y + z * 2);
		cout << ans << "\n";
		rep(i, 0, best_x) cout << mi << " ";
		rep(i, 0, best_y) cout << mi + 1 << " ";
		rep(i, 0, best_z) cout << mi + 2 << " ";
		cout << "\n";
	} else if (ma == mi) {
		cout << n << "\n";
		rep(i, 0, n) cout << mi << " ";
		cout << "\n";
	} else {
		int x = 0, y = 0, z = 0;
		rep(i, 0, n) {
			assert(0 <= a[i] && a[i] <= 2);
			if (a[i] == 0) x++;
			else if (a[i] == 1) y++;
			else z++;
		}
		assert(ma == mi + 1);
		int ans = INF;
		int best_x = -1, best_y = -1;
		rep(yy, 0, n + 1) {
			int xx = n - yy;
			if (yy != y) continue;
			if (mini(ans, min(x, xx) + min(y, yy))) {
				best_x = xx;
				best_y = yy;
			}
		}
		cout << ans << "\n";
		rep(i, 0, best_x) cout << mi << " ";
		rep(i, 0, best_y) cout << mi + 1 << " ";
		cout << "\n";
	}
}