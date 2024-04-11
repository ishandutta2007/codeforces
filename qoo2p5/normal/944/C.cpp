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
int p[N];
vector<int> g[N];
int cnt[N];
int depth[N];

void dfs(int v) {
	cnt[depth[v]]++;
	for (int u : g[v]) {
		depth[u] = depth[v] + 1;
		dfs(u);
	}
}

void run() {
	cin >> n;
	rep(i, 2, n + 1) {
		cin >> p[i];
		g[p[i]].pb(i);
	}
	dfs(1);
	int ans = 0;
	rep(i, 0, n + 1) {
		cnt[i] %= 2;
		ans += cnt[i];
	}
	cout << ans << "\n";
}