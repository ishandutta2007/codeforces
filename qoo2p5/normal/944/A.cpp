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

void run() {
	ll n, a, b;
	cin >> n >> a >> b;
	int ans = INF;
	int k = 1;
	while ((1 << k) < n) k++;
	if (a > b) swap(a, b);
	a--; b--;
	rep(i, 0, k) {
		for (int j = 0; j < n; j += (1 << (i + 1))) {
			int l1 = j;
			int r1 = j + (1 << i) - 1;
			int l2 = r1 + 1;
			int r2 = l2 + (1 << i) - 1;
			if (l1 <= a && a <= r1 && l2 <= b && b <= r2) {
				ans = i;
			}
		}
	}
	assert(ans != INF);
	if (ans == k - 1) {
		cout << "Final!\n";
	} else {
		cout << ans + 1 << "\n";
	}
}