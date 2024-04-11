#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

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

const int N = 5005;
const int K = 30;

int n;
string s;
int a[N];
int cnt[K];
int cc[K][K][N];

void run() {
	cin >> s;
	n = sz(s);
	rep(i, 0, n) {
		a[i] = s[i] - 'a';
		cnt[a[i]]++;
	}
	
	rep(i, 0, n) {
		rep(dist, 1, n) {
			cc[a[i]][a[(i + dist) % n]][dist]++;
		}
	}
	
	ld ans = 0;
	
	rep(first, 0, K) {
		ld best = 0;
		rep(pos, 1, n) {
			int good = 0;
			int total = 0;
			rep(j, 0, K) {
				total += cc[first][j][pos];
				if (cc[first][j][pos] == 1) {
					good++;
				}
			}
			maxi(best, (ld)good / (ld)total);
		}
		ans += best * ((ld)cnt[first] / (ld)n);
	}
	
	cout << fixed << setprecision(15);
	cout << ans << "\n";
}