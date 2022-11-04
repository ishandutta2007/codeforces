#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define ld long double
#define sz(x) (int) x.size()
#define INF (int) 1e9
#define LINF (ll) 1e18
#define EPS 1e-10
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eq(a, b) abs(a - b) < EPS

const ll mod = 1000000007;

ll p, k;
vector<ll> g[1000500];
bool visited[1000500];
bool flag = false;

int dfs(ll v) {
	int s = 1;
	visited[v] = true;

	for (ll to : g[v]) {
		if (to == v) {
			flag = true;
		}
		if (!visited[to]) {
			s += dfs(to);
		}
	}

	return s;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);

	cin >> p >> k;

	if (k == 0) {
		ll ans = 1;
		for (int i = 0; i <= p - 2; i++) {
			ans *= p;
			ans %= mod;
		}
		cout << ans << endl;
		return 0;
	}

	if (k == 1) {
		ll ans = 1;
		for (int i = 0; i <= p - 1; i++) {
			ans *= p;
			ans %= mod;
		}
		cout << ans << endl;
		return 0;
	}

	for (ll x = 0; x <= p - 1; x++) {
		ll y = (k * x) % p;
		g[x].pb(y);
		g[y].pb(x);
	}

	ll ans = 1;
	for (int i = 0; i <= p - 1; i++) {
		if (!visited[i]) {
			flag = false;
			dfs(i);

			if (flag) {
				// then f(smth) = 0, and everything is fixed
			} else {
				ans *= p;
				ans %= mod;
			}
		}
	}

	cout << ans << endl;
	return 0;
}